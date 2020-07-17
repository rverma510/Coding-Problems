#include <assert.h>

class Point {
  public:
    Point(int x, int y): x(x), y(y) {}
    Point operator+(Point p) {
        return Point(x+p.x, y+p.y);
    }
    int x;
    int y;
};
int main() {
  Point p1(10, 5), p2(2, 4);
  Point p3 = p1 + p2; // An example call to "operator +";
  assert(p3.x == p1.x + p2.x);
  assert(p3.y == p1.y + p2.y);
}