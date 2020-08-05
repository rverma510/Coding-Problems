#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1, mutex2;

void threadA() {
    mutex1.lock();
    std::cout << "Thread A" << std::endl;
    mutex2.lock();
    mutex2.unlock();
    mutex1.unlock();
}

void threadB() {
    mutex2.lock();
    std::cout << "Thread B" << std::endl;
    mutex1.lock();
    mutex1.unlock();
    mutex2.unlock();
}

int main() {
    std::thread t1(threadA);
    std::thread t2(threadB);

    t1.join();
    t2.join();

    std::cout << "Finished" << std::endl;
    return 0;
}