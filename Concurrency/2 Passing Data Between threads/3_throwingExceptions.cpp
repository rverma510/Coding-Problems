#include <iostream>
#include <thread>
#include <future>
#include <chrono>

void divideByNumber(std::promise<double> &&prms, double num, double den) {
    try {
        if (den == 0) {
            throw std::runtime_error("Exception from thread: Divide By Zero!");
        } 
        else {
            prms.set_value(num / den);
        }
    }
    catch(...) {
        prms.set_exception(std::current_exception());
    }
}

int main() {
    double num = 42.0;
    double den = 0;
    std::promise<double> prms;
    std::future<double> ftr = prms.get_future();

    std::thread t(divideByNumber, std::move(prms), num, den);
    
    try {
        std::cout << "Result = " << ftr.get() << std::endl;
    }
    catch(std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }

    t.join();
    return 0;
}