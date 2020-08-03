#include <iostream>
#include <thread>
class Vehicle {
  public:
    void operator()() {
        std::cout << "Vehicle object has been created\n";
    }
};

int main() {
    // std::thread t(Vehicle()) // C++ most vexing parse
    /*
    1. a variable definition for variable t of class std::thread, initialized with an anonymous 
    instance of class Vehicle or
    2. a function declaration for a function t that returns an object of type std::thread and has 
    a single (unnamed) parameter that is a pointer to function returning an object of type Vehicle
    */
    std::thread t1((Vehicle())); // using extra paranthesis
    std::thread t2 = std::thread(Vehicle()); // using copy constructor
    std::thread t3{Vehicle()}; // using uniform initialization

    std::cout << "Finished work in main\n";
    
    t1.join();
    t2.join();
    t3.join();

    return 0;
}