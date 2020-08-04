#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <cmath>
#include <chrono>

void workerFunction(int n) {
    std::cout << "Worker thread id = " << std::this_thread::get_id() << std::endl;

    for (int i = 0; i < n; i++) {
        sqrt(12345.67890);
    } 
}

int main() {
    std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;

    auto t1 = std::chrono::high_resolution_clock::now();

    std::vector<std::future<void>> futures;
    int nLoops = 10, nThreads = 5;
    for (int i = 0; i < nThreads; i++) {
        futures.emplace_back(std::async(std::launch::deferred, workerFunction, nLoops));
    }

    for (const std::future<void> &ftr: futures) 
        ftr.wait();

    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << "Execution finished after " << duration << " microseconds" << std::endl;

    return 0;
}

// nLoops = 1e7, launch = async    : Execution finished after 49 microseconds
// nLoops = 1e7, launch = deferred : Execution finished after 164 microseconds
// nLoops = 10, launch = async     : Execution finished after 0 microseconds
// nLoops = 10, launch = deferred  : Execution finished after 0 microseconds