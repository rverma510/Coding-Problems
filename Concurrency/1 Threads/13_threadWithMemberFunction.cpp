#include <iostream>
#include <thread>
#include <memory>
#include <string>

class Vehicle {
  public:
    Vehicle(): _id(0), _name("null") {};
    void setId(int id) { _id = id; }
    void setName(std::string name) { _name = name; }
    void printId() { std::cout << "Vehicle Id = " << _id << std::endl; }
    void printName() { std::cout << "Vehicle Name = " << _name << std::endl; }
  private:
    int _id;
    std::string _name;
};

int main() {
    std::shared_ptr<Vehicle> v = std::make_shared<Vehicle>();
    std::thread t1 = std::thread(&Vehicle::setId, v, 1);
    std::thread t2 = std::thread(&Vehicle::setName, v, "BMW");

    t1.join();
    t2.join();

    v->printId();
    v->printName();
    
    return 0;
}