#include <bits/stdc++.h>
using namespace std;
enum class Car {
    Mercedes,
    BMW,
    Audi,
    Ford,
    GM,
    Maruti,
    Honda,
    Mahindra
};
int main() {
    Car mustang = Car::Ford;
    switch(mustang) {
        case Car::Mercedes : {
            cout << "It is a Mercedes\n";
        }
        break;
        case Car::BMW : {
            cout << "It is a BMW\n";
        }
        break;
        case Car::Audi : {
            cout << "It is a Audi\n";
        }
        break;
        case Car::Ford : {
            cout << "It is a Ford\n";
        }
        break;
        case Car::GM : {
            cout << "It is a GM\n";
        }
        break;
        case Car::Maruti : {
            cout << "It is a Maruti\n";
        }
        break;
        case Car::Honda : {
            cout << "It is a Honda\n";
        }
        break;
        case Car::Mahindra : {
            cout << "It is a Mahindra\n";
        }
        break;
        default : {
            cout << "Default case\n";
        }
    }


    return 0;
}