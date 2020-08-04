#include <iostream>
#include <thread>
#include <cmath>
#include <future>

void modifyMessage(std::promise<double> &&prms, double input) {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    double output = sqrt(input);
    prms.set_value(output);
}

int main() {
    double input = 42.0;
    std::promise<double> prms;
    std::future<double> ftr = prms.get_future();

    std::thread t(modifyMessage, std::move(prms), input);
    auto status = ftr.wait_for(std::chrono::milliseconds(1000));
    if (status == std::future_status::ready) {
        std::cout << "Result = " << ftr.get() << std::endl;
    }
    else if(status == std::future_status::timeout || status == std::future_status::deferred) {
        std::cout << "Result unavailable" << std::endl;
    }

    t.join();
    return 0;
}