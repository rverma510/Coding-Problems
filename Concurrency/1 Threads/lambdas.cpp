#include <iostream>
using namespace std;

int main() {
    int id = 0;
    
    // auto f0 = []() { cout << "The id is " << id << endl; }; // id cannot be accessed. Not in capture list
    
    id++;
    auto f1 = [id]() { cout << "The id is " << id << endl; }; // OK. id is captured by value

    id++;
    auto f2 = [&id]() { cout << "The id is " << id << endl; }; // OK. id is captured by reference

    //auto f3 = [id]() { cout << "The id is " << ++id << endl; } // Error. id may not be modified

    auto f4 = [id]() mutable { cout << "The id is " << ++id << endl; };

    auto f5 = [](int id) { cout << "The id is " << id << endl; };

    f1();
    f2();
    f4();
    f5(5);

    cout << "Finally the id is " << id << endl;

    return 0;
}