#include <cassert>
#include <cmath>
#include <stdexcept>
using namespace std;
// TODO: Define class Sphere
class Sphere {
 public:
    Sphere(float radius) {
      this->radius = radius;
      validate();
      calculateVolume();  
    }
    float Radius() const {
        return radius;
    }
    void Radius(float radius) {
        this->radius = radius;
        validate();
        calculateVolume();
    }
    float Volume() const {
        return volume;
    }
    void validate() {
        if (radius < 0)
            throw std::invalid_argument("radius can not be negative");
    }
 private:
    void calculateVolume() {
        volume = (4.0 / 3.0) * 2*asin(1.0) * (pow(radius, 3)); 
    }
    float radius{0};
    float volume{0};
};

// Test
int main(void) {
  Sphere sphere(5);
  assert(sphere.Radius() == 5);
  assert(abs(sphere.Volume() - 523.6) < 1);
}