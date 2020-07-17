#include <assert.h>
#include <cmath>
#define pi 3.14159
class VehicleModel {
  public:
    virtual void Move(double, double) = 0;
};

class ParticleModel: public VehicleModel {
  public:
    void Move(double v, double phi) override{
        theta += phi;
        x += v * cos(theta);
        y += v * cos(theta);
    }
    float x{0};
    float y{0};
    float theta{0};
};

class BicycleModel: public ParticleModel {
  public:
    void Move(double v, double phi) override{
        theta += v / L * tan(phi);
        x += v * cos(theta);
        y += v * cos(theta);
    }
    float L{1};
};
// TODO: Pass the tests
int main() {
  // Test function overriding
  ParticleModel particle;
  BicycleModel bicycle;
  particle.Move(10, pi / 9);
  bicycle.Move(10, pi / 9);
  assert(particle.x != bicycle.x);
  assert(particle.y != bicycle.y);
  assert(particle.theta != bicycle.theta);
}