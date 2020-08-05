#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include <algorithm>
#include <future>
#include <mutex>

class Vehicle {
  public:
    Vehicle(int id): _id(id) {}
  private:
    int _id;
};

class WaitingVehicles {
  public:
    WaitingVehicles() {}
    void printSize() {
        _mutex.lock();
        std::cout << "The size = " << _vehicles.size() << std::endl;
        _mutex.unlock();
    }
    void pushBack(Vehicle && v) {
        _mutex.lock();
        _vehicles.push_back(std::move(v));
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        _mutex.unlock();
    }
  private:
    std::vector<Vehicle> _vehicles;
    std::mutex _mutex;
};

int main() {
    std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);   
    std::vector<std::future<void>> futures;
    for (int i = 1; i <= 1000; i++) {
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
    }
    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
        ftr.wait();
    });

    queue->printSize();

    return 0;
}