#include <iostream>
#include "IO.hpp"
#include <fstream>

using std::string;
using std::fstream;
using std::endl;

IO::IO(const std::string &filePath){
    fileStream.open(filePath, std::ios::in | std::ios::out | std::ios::binary);
    if(!fileStream.is_open()){
        std::cerr << "Error: Could not open file: " <<filePath<< std::endl;
    }
}

std::fstream IO::getFileStream(){
  return std::move(fileStream);
}

IO::~IO(){
    if(fileStream.is_open()) fileStream.close();
}