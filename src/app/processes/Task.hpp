#ifndef TASK_HPP
#define TASK_HPP
#include <string>
#include <iostream>
#include <sstream>
#include "../fileHandling/IO.hpp"

using std::string;

enum class Action
{
    ENCRYPT,
    DECRYPT
};

struct Task
{
    string filePath;
    std::fstream fileStream;
    Action action;

    Task(std::fstream &&stream, Action act, string filePath) : fileStream(std::move(stream)), action(act), filePath(filePath){};

    string toString()
    {
        std::ostringstream oss;
        oss << filePath << "," << (action == Action::ENCRYPT ? "ENCRYPT" : "DECRYPT");
        return oss.str();
    }

    static Task fromString(const std::string &taskData)
    {
        std::istringstream iss(taskData);
        string filePath;
        string actionStr;
        if (std::getline(iss, filePath, ',') && std::getline(iss, actionStr))
        {
            Action action = actionStr == "ENCRYPT" ? Action::ENCRYPT : Action::DECRYPT;
            IO io(filePath);
            std::fstream fileStream = std::move(io.getFileStream());
            if (fileStream.is_open())
            {
                return Task(std::move(fileStream), action, filePath);
            }
            else
            {
                throw std::runtime_error("Error: Could not open file: " + filePath);
            }
        }
        else
        {
            throw std::runtime_error("Error: Invalid task data: " + taskData);
        }
    }
    
};


#endif