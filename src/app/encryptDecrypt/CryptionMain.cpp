#include <iostream>
#include "Cryption.hpp"

int main(int argc, char *argv[]){
    if(argc != 2){
        std::cerr << "Error: Usage: ./cryption <task_data>" << std::endl;
        return 1;
    }
    std::string taskData = argv[1];
    executeCryption(taskData);
    return 0;
}