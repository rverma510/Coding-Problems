#include <iostream>
using namespace std;

class Human {};
class Dog {}; 
class Cat {};

void hello() {
    cout << "Hello\n";
}

void hello(Human human) {
    cout << "Hello, human\n";
}

void hello(Dog dog) {
    cout << "Hello, dog\n";
}

void hello(Cat cat) {
    cout << "Hello, cat\n";
}

int main() {
    hello();
    hello(Human());
    hello(Dog());
    hello(Cat());

}