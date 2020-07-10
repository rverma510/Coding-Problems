#include <iostream>
using std::cout;
int main() {
    enum class Direction {kUp, kDown, kLeft, kRight};
    Direction my_direction = Direction::kRight;
    switch(my_direction) {
        case Direction::kUp : 
                            cout<<"Going up!";
                            break;
        case Direction::kDown : 
                            cout<<"Going down!";
                            break;
        case Direction::kLeft : 
                            cout<<"Going left!";
                            break;
        case Direction::kRight : 
                            cout<<"Going Right!";
                            break;    
    }

    return 0;
}