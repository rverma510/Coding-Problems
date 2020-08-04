#include <iostream>
#include <thread>
#include <future>

double divideByNumber(double num, double den) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    if (den == 0)
        throw std::runtime_error("Runtime Error: divide By zero!");
    return num / den;
}

int main() {
    double num = 42.0;
    double den = 10.0;

    std::future<double> ftr = std::async(divideByNumber, num, den);
    
    try {
        double res = ftr.get();
        std::cout << "Result = " << res << std::endl;
    }
    catch(std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}