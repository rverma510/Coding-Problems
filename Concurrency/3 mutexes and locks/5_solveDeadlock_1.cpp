#include <iostream>
#include <thread>
#include <future>
#include <mutex>
#include <vector>
#include <algorithm>

double result;
std::mutex _mutex;

void printResult(int den) {
    std::cout << "for denom " << den << ", the result is " << result << std::endl;
}

void divideByNumber(double num, double den) {
    try {
        if (den != 0) {
            _mutex.lock();
            result = num / den;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            printResult(den);
            _mutex.unlock();
        }
        else {
            throw std::invalid_argument("Error! divide by zero error");
        }
    }
    catch(std::invalid_argument e) {
        std::cout << e.what() << std::endl;
        return;
    }
}

int main() {
    std::vector<std::future<void>> futures;
    for (int i = -5; i <= 5; i++) {
        futures.emplace_back(std::async(std::launch::async, divideByNumber, 50.0, i));
    }
    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
        ftr.wait();
    });
    return 0;
}