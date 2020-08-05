// Monitor Object Pattern
#include <iostream>
#include <thread>
#include <future>
#include <mutex>
#include <vector>
#include <algorithm>

class Vehicle {
  public:
    Vehicle(int id): _id(id) {}
    int getId() { return _id; }
  private:
    int _id;
};

class WaitingVehicles {
  public:
    WaitingVehicles() {}
    int getCount() {
        std::lock_guard<std::mutex> lck(_mutex);
        return _cnt;
    }
    bool dataIsAvailable() {
        std::lock_guard<std::mutex> lck(_mutex);
        return !_vehicles.empty();
    }
    void pushBack(Vehicle &&v) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        std::lock_guard<std::mutex> lck(_mutex);

        std::cout << "Vehicle Id #" << v.getId() << " added to queue" << std::endl;
        _vehicles.emplace_back(std::move(v));
        _cnt++;

    }
    Vehicle popBack() {
        std::lock_guard<std::mutex> lck(_mutex);
        Vehicle v = std::move(_vehicles.back());
        _vehicles.pop_back();
        _cnt--;
        return v;
    }
  private:
    std::vector<Vehicle> _vehicles;
    std::mutex _mutex;
    int _cnt = 0;
};

int main() {
std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);

    std::cout << "Spawning threads..." << std::endl;
    std::vector<std::future<void>> futures;
    for (int i = 0; i < 10; ++i)
    {
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::cout << "Collecting results..." << std::endl;
    while (true)
    {
        if (queue->dataIsAvailable())
        {
            Vehicle v = queue->popBack();
            std::cout << "Vehicle #" << v.getId() << " has been removed from the queue" << std::endl;

            if(queue->getCount()<=0)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
                break;
            }
        }
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
        ftr.wait();
    });

    std::cout << "Finished : " << queue->getCount() << " vehicle(s) left in the queue" << std::endl;

    return 0;
}