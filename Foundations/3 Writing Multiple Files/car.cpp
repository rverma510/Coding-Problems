#include <iostream>
#include "car.h"

void Car::PrintCarData() {
    cout << "The distance that the " << color << " car " << number << " has travelled is : " << distance << "\n"; 
}

void Car::IncrementDistance() {
    distance++;
}