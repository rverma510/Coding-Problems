#include <iostream>
#include <thread>
#include <string>

void printId(int id) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Printing ID : " << id << std::endl;
}

void printIdAndName(int id, std::string name) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Printing ID : " << id << " and NAME : " << name << std::endl;
}

int main() {
    std::string name1 = "name1", name2 = "name2";
    std::thread t0(printId, 1);

    std::thread t1(printIdAndName, 2, name1);
    std::thread t2(printIdAndName, 3, std::move(name2));
    t0.join();
    t1.join();
    t2.join();

    std::cout << "name1 = " << name1 << std::endl;
    std::cout << "name2 = " << name2 << std::endl;
      
    return 0;
}