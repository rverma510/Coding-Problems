#include <iostream>
#include <future>
#include <thread>

double divideByNumber(double num, double den) {
    std::cout << "Worker Thread ID : " << std::this_thread::get_id() << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    if (den == 0)
        throw std::runtime_error("Runtime Error: divide by zero!");

    return num / den;
}

int main() {
    std::cout << "Main Thread ID : " << std::this_thread::get_id() << std::endl;

    double num = 42.0, den = 0;
    std::future<double> ftr = std::async(std::launch::deferred, divideByNumber, num, den);
    // std::launch::async
    try {
        double res = ftr.get();
        std::cout << "Result = " << res << std::endl;
    } 
    catch(std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}