#include <iostream>
#include <thread>
#include <future>

std::mutex mutex1, mutex2;

void threadA() {
    std::lock(mutex1, mutex2);
    std::lock_guard<std::mutex>(mutex2, std::adopt_lock);
    std::cout << "Thread A" << std::endl;
    std::lock_guard<std::mutex>(mutex1, std::adopt_lock);
}

void threadB() {
    std::lock(mutex1, mutex2);
    std::lock_guard<std::mutex>(mutex1, std::adopt_lock);
    std::cout << "Thread B" << std::endl;
    std::lock_guard<std::mutex>(mutex2, std::adopt_lock);
}

void Execute() {
    std::thread t1(threadA);
    std::thread t2(threadB);

    t1.join();
    t2.join();

    std::cout << "Finished" << std::endl;
}

int main() {
    Execute();

    return 0;
}