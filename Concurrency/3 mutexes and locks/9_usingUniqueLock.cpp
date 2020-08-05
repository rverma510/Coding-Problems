#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <future>
#include <algorithm>

double result;
std::mutex mtx;

void printResult(double den) {
    std::cout << "for denom " << den <<", the result is " << result << std::endl;
}

void divideByNumber(double num, double den) {
    std::unique_lock<std::mutex> lck(mtx);
    try {
        if (den != 0) {
            result = num / den;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            printResult(den);

            lck.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            lck.lock();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        else {
            throw std::runtime_error("Error: Divide By Zero");
        }
    }
    catch(std::runtime_error e) {
        std::cout << e.what() << std::endl;
        return;
    }
}

int main() {
    std::vector<std::future<void>> futures;
    for (int i = -5; i <= 5; i++) {
        futures.emplace_back(std::async(std::launch::async, divideByNumber, 50.0, i));
    }
    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr){
        ftr.wait();
    });
    return 0;
}