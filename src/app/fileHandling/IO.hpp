#ifndef IO_HPP
#define IO_HPP

#include <fstream>
#include <string>
#include <iostream>

class IO{
    public:
    IO(const std::string &filePath);
    ~IO();
    std::fstream getFileStream();

    private:
    std::fstream fileStream;
};

#endif