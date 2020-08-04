#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < 10; i++) {
        
        threads.emplace_back([i]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(10 * i));

            std::cout << "Hello from worker thread #" << i << std::endl;
        });
    }

    std::cout << "Hello from main thread\n";

    for (auto &i: threads) 
        i.join();
    
    return 0;
}