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
        std::cout << "Vehicle #" << _id << " Default constructor called" << std::endl;
    }
    std::string getName() { return *_name; }
    int getId() { return _id; }
    void setName(std::string name) { *_name = name; }
    void setId(int id) { _id = id; }
 private:
    int _id;
    std::string *_name;
};

int main() {
    Vehicle v0;
    Vehicle v1(1, "Vehicle 1");

    std::future<void> ftr = std::async([](Vehicle v) {
        // std::this_thread::sleep_for(std::chrono::milliseconds(500));
        v.setName("Vehicle 2");
    }, v0);

    v0.setName("Vehicle 3");

    ftr.wait();
    std::cout << v0.getName() << std::endl;
    return 0;
}