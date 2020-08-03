#include <iostream>
#include <thread>

void printId(int &id) {
    id++;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Printing ID : " << id << std::endl;
}

int main() {
    int id = 1;
    std::thread t(printId, std::ref(id));

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Printing ID in main : " << id << std::endl;
    t.join();

    return 0;
}