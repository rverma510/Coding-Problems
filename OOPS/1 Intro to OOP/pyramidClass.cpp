#include <cassert>
#include <stdexcept>
#include <iostream>
using namespace std;
class Pyramid {
  public:
    Pyramid(int l, int w, int h) {
        Length(l);
        Width(w);
        Height(h);
    } 
    void Length(int);
    void Width(int);
    void Height(int);
    int Length() const;
    int Width() const;
    int Height() const;
    float Volume();
  private:
    int length;
    int width;
    int height;
};
void Pyramid::Length(int l) {
    if (l >= 1)
        length = l;
    else
        throw std::invalid_argument("negative dimension");
}
void Pyramid::Width(int w) {
    if (w >= 1)
        width = w;
    else
        throw std::invalid_argument("negative dimension");
}
void Pyramid::Height(int h) {
    if (h >= 1)
        height = h;
    else
        throw std::invalid_argument("negative dimension");
}
int Pyramid::Length() const {
    return length;
}
int Pyramid::Width() const {
    return width;
}
int Pyramid::Height() const {
    return height;
}
float Pyramid::Volume() {
    return (length * width * height) / 3;
}

int main() {
  Pyramid pyramid(4, 5, 6);
  assert(pyramid.Length() == 4);
  assert(pyramid.Width() == 5);
  assert(pyramid.Height() == 6);
  assert(pyramid.Volume() == 40);
  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}