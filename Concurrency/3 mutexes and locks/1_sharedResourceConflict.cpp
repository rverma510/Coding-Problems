#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include <algorithm>
#include <future>

class Vehicle {
  public:
    Vehicle(int id): _id(id) {}
  private:
    int _id;
};

class WaitingVehicles {
  public:
    WaitingVehicles(): _tmp(0) {}
    void printSize() {
        std::cout << "The size = " << _tmp << std::endl;
    }
    void pushBack(Vehicle && v) {
        // _vehicles.push_back(std::move(v));
        int oldnum = _tmp;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        _tmp = oldnum + 1;
    }
  private:
    std::vector<Vehicle> _vehicles;
    int _tmp;
};

int main() {
    std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);   
    std::vector<std::future<void>> futures;
    for (int i = 1; i <= 1000; i++) {
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
        // futures[futures.size() - 1].wait();
    }
    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
        ftr.wait();
    });

    queue->printSize();

    return 0;
}