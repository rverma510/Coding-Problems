#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    int wheels = 0;
    string color = "blue";
    float weight = 0;
    
    void Print() const
    {
        std::cout << "This " << color << " vehicle has " << wheels 
            << " wheels and " << weight << " weight!\n" ;
    }
};

class Car : public Vehicle {
public:
    bool sunroof = false;
};

class Bicycle : public Vehicle {
public:
    bool kickstand = true;
};

class Truck : public Vehicle {
    public:
    float load = 0;
    void Print() const {
        Vehicle::Print();
        std::cout << "The load of truck is : " << load << std::endl;
    }
};

int main() 
{
    Car car;
    car.wheels = 4;
    car.weight = 1000;
    car.sunroof = true;
    car.Print();
    if(car.sunroof)
        std::cout << "And a sunroof!\n";
    Truck truck;
    truck.color = "red";
    truck.wheels = 10;
    truck.weight = 5000;
    truck.load = 1000;
    truck.Print();
    
};