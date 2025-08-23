#include "Cryption.hpp"
#include "../processes/Task.hpp"
#include "../fileHandling/ReadENV.cpp"


int executeCryption(const std::string &taskData){
    Task task = Task::fromString(taskData);
    ReadENV env;
    std::string envKey = env.getenv();
    int key = std::stoi(envKey);
    if(task.action == Action::ENCRYPT){
        char ch;
        while(task.fileStream.get(ch)){
            ch = (ch + key) % 256;
            task.fileStream.seekp(-1, std::ios_base::cur);
            task.fileStream.put(ch);
        }
        task.fileStream.close();
    } else {
        char ch;
        while(task.fileStream.get(ch)){
            ch = (ch - key + 256) % 256;
            task.fileStream.seekp(-1, std::ios_base::cur);
            task.fileStream.put(ch);
        }
        task.fileStream.close();
    }
    return 0;
}