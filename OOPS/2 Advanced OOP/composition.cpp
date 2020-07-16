#include <iostream>
#include <cmath>
#include <assert.h>
#define pi 3.14159

class LineSegment {
    float length;
  public:
    LineSegment(float length) :length(length) {}
    float getLength() const {
        return length;
    }
    void setLength(float length) {
        this->length = length;
    }
};

class Circle {
    LineSegment lineSegment;
    public:
    Circle(LineSegment obj) : lineSegment(obj) {}
    float Area() {
       return pi * pow(lineSegment.getLength(), 2); 
    }
};

int main() 
{
    LineSegment radius {3};
    Circle circle(radius);
    assert(int(circle.Area()) == 28);
}