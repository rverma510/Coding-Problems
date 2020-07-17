// Example solution for Shape inheritance
#include <assert.h>
#include <cmath>
using namespace std;
#define pi 3.14159

class Shape {
  public:
    virtual float Area() = 0;
    virtual float Perimeter() = 0;
    
};

class Rectangle: public Shape {
  public:
    Rectangle(float h, float w): height(h), width(w) {}
    float Area() {
        return height * width;
    }
    float Perimeter() {
        return 2 * (height + width);
    }
  private:
    float height;
    float width;
};

class Circle: public Shape {
  public:
    Circle(float r): radius(r) {}
    float Area() {
        return pi * radius * radius;
    }
    float Perimeter() {
        return 2 * pi * radius;
    }
  private:
    float radius;
};

int main() {
  double epsilon = 0.1; // useful for floating point equality

  // Test circle
  Circle circle(12.31);
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);

  // Test rectangle
  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
}