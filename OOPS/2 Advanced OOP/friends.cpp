// Example solution for Rectangle and Square friend classes
#include <assert.h>

class Square {
    float side{0};
    friend class Rectangle;
  public:
    Square(float s): side(s) {}
};

class Rectangle {
    float height{0};
    float width{0};
  public:
    Rectangle(Square sq): height(sq.side), width(sq.side) {}
    float Area() {
        return height * width;
    }
};

int main()
{
    Square square(4);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16); 
}