#include <iostream>
#include <thread>
#include <future>
#include <string>

void modifyMessage(std::promise<std::string> &&prms, std::string message) {
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    std::string modifiedMessage = message + " has been modified";
    prms.set_value(modifiedMessage);
}

int main() {

    std::string message = "My message";

    std::promise<std::string> prms;
    std::future<std::string> ftr = prms.get_future();

    std::thread t(modifyMessage, std::move(prms), message);

    std::cout << "The message = " << message << std::endl;
    
    std::string modifiedMessage = ftr.get();

    std::cout << "The modified message = " << modifiedMessage << std::endl;

    t.join();
    return 0;
}