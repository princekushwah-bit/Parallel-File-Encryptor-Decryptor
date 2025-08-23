#include "ProcessManagement.hpp"
#include <iostream>
#include <string>
#include "../encryptDecrypt/Cryption.hpp"
#ifdef __unix__
#include <sys/wait.h>
// Unix-specific code
#elif defined(_WIN32) || defined(WIN32)
// Windows-specific headers and code
#endif


ProcessManagement::ProcessManagement(){}

bool ProcessManagement::submitToQueue(std::unique_ptr<Task> task){
    taskQueue.push(std::move(task));
    return true;
}

void ProcessManagement::executeTasks(){
    while(!taskQueue.empty()){
        std::unique_ptr<Task> taskToExecute = std::move(taskQueue.front());
        taskQueue.pop();
        std::cout << "Executing task: " << taskToExecute->toString() << std::endl;
        executeCryption(taskToExecute->toString());
    }
}
