#include <iostream>
#include <thread>
#include <future>
#include <string>

class Vehicle {
  public:
    Vehicle(): _id(0), _name(new std::string("Default name")) {
        std::cout << "Vehicle #" << _id << " Default constructor called" << std::endl;
    }
    Vehicle(int id, std::string name): _id(id), _name(new std::string(name)) {
        std::cout << "Vehicle #" << _id << " Initializing constructor called" << std::endl;
    }
    Vehicle(Vehicle &&v): _name(std::move(v._name)) {
        _id = v._id;
        v._id = 0;
        std::cout << "Vehicle #" << _id << " move constructor called" << std::endl;
    }
    std::string getName() { return *_name; }
    int getId() { return _id; }
    void setName(std::string name) { *_name = name; }
    void setId(int id) { _id = id; }
 private:
    int _id;
    std::unique_ptr<std::string> _name;
};

int main() {
    Vehicle v0;
    Vehicle v1(1, "Vehicle 1");

    std::future<void> ftr = std::async([](Vehicle v) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        v.setName("Vehicle 2");
    }, std::move(v0));


    ftr.wait();
    // std::cout << v0.getName() << std::endl;
    return 0;
}