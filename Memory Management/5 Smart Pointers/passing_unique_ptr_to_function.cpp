#include <iostream>
#include <memory>
using namespace std;

class MyClass {
  private:
    int _member;
  public:
    MyClass(int val): _member(val) {}
    void print() {
        cout << ", managed object " << this << " with value " << _member << "\n";
    }
};

void func(unique_ptr<MyClass> obj) {
    cout << "Unique pointer " << &obj;
    obj->print();
}

int main() {
    unique_ptr<MyClass> obj = make_unique<MyClass>(176);
    cout << "Unique pointer " << &obj;
    obj->print();

    func(move(obj));

    if (obj)
        obj->print();
    return 0;
}