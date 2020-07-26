#include <iostream>
using namespace std;

class Point {
  public:
    int x, y;
    Point(int x, int y): x(x), y(y) {}
    int dis(Point p) {
        return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
    }
};

bool checkSquare(Point p1, Point p2, Point p3, Point p4) {
    int d2 = p1.dis(p2);
    int d3 = p1.dis(p3);
    int d4 = p1.dis(p4);
    if (d2 == 0 || d3 == 0 || d4 == 0)
        return false;
    if (d2 == d3 && 
        2 * d2 == d4 &&
        2 * p2.dis(p4) == p2.dis(p3))
        return true;
    if (d2 == d4 &&
        2 * d2 == d3 &&
        2 * p2.dis(p3) == p2.dis(p4))
        return true;
    if (d3 == d4 &&
        2 * d3 == d2 &&
        2 * p3.dis(p2) == p3.dis(p4))
        return true;
    return false;
}

int main() {
    int x, y;
    cin >> x >> y;
    Point p1(x, y);
    cin >> x >> y;
    Point p2(x, y);
    cin >> x >> y;
    Point p3(x, y);
    cin >> x >> y;
    Point p4(x, y);
    
    cout << checkSquare(p1, p2, p3, p4) << endl;
    return 0;
}