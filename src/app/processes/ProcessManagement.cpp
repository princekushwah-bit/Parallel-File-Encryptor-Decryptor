#include "ProcessManagement.hpp"
#include <iostream>
#include <string>
#include "../encryptDecrypt/Cryption.hpp"

ProcessManagement::ProcessManagement(size_t numThreads) : stop(false) {
    for(size_t i = 0; i < numThreads; i++) {
        workers.emplace_back(&ProcessManagement::workerThread, this);
    }
}

ProcessManagement::~ProcessManagement() {
    stop = true;
    cv.notify_all();
    for(auto &t : workers) {
        if(t.joinable()) t.join();
    }
}

bool ProcessManagement::submitToQueue(std::unique_ptr<Task> task) {
    {
        std::lock_guard<std::mutex> lock(queueMutex);
        taskQueue.push(std::move(task));
    }
    cv.notify_one();
    return true;
}

void ProcessManagement::executeTasks() {
    // Wait until all tasks finish
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        cv.wait(lock, [this]() { return taskQueue.empty(); });
    }
    // Allow workers to finish pending tasks
}

void ProcessManagement::workerThread() {
    while(true) {
        std::unique_ptr<Task> taskToExecute;

        {
            std::unique_lock<std::mutex> lock(queueMutex);
            cv.wait(lock, [this]() { return stop || !taskQueue.empty(); });

            if(stop && taskQueue.empty()) return;

            taskToExecute = std::move(taskQueue.front());
            taskQueue.pop();
        }

        if(taskToExecute) {
            std::cout << "Thread " << std::this_thread::get_id()
                      << " executing task: " << taskToExecute->toString() << std::endl;
            executeCryption(taskToExecute->toString());
        }

        cv.notify_all();
    }
}
