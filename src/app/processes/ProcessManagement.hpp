#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP

#include "Task.hpp"
#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <vector>
#include <atomic>

class ProcessManagement {
public:
    ProcessManagement(size_t numThreads = std::thread::hardware_concurrency());
    ~ProcessManagement();

    bool submitToQueue(std::unique_ptr<Task> task);
    void executeTasks();

private:
    void workerThread();

    std::queue<std::unique_ptr<Task>> taskQueue;
    std::mutex queueMutex;
    std::condition_variable cv;
    std::vector<std::thread> workers;
    std::atomic<bool> stop;
};

#endif
