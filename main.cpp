#include <iostream>
#include <filesystem>
#include "./src/app/processes/ProcessManagement.hpp"
#include "./src/app/processes/Task.hpp"

namespace fs = std::filesystem;

using std::string;

int main(int argc, char *argv[]){
    string directory;
    string action;
    std::cout<<"'Enter the directory path: "<<std::endl;
    std::getline(std::cin, directory);
     std::cout<<"'Enter the action (encrypt/decrypt): "<<std::endl;
    std::getline(std::cin, action);

    try {
       if(fs::exists(directory) && fs::is_directory(directory)) {
         ProcessManagement processManagement;
         for(const auto &entry: fs::recursive_directory_iterator(directory)){
            if(entry.is_regular_file()){
                string filePath = entry.path().string();
                IO io(filePath);
                std::fstream fileStream = std::move(io.getFileStream());
                if(fileStream.is_open()){
                  Action taskAction = (action == "encrypt") ? Action::ENCRYPT : Action::DECRYPT;
                  auto task = std::make_unique<Task>(std::move(fileStream), taskAction, filePath);
                  processManagement.submitToQueue(std::move(task));
                } else {
                  std::cout<<"Error: Could not open file: "<<filePath<<std::endl;
                }
            }
         }
         processManagement.executeTasks();
       } else {
          std::cout<<"Error: Directory does not exist: "<<directory<<std::endl;
       }
    } catch(const fs::filesystem_error &e) {
      std::cout<<"FileSystem Error: "<<e.what()<<std::endl;

    }

}