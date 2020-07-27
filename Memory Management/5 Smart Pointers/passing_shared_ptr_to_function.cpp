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

void func(shared_ptr<MyClass> obj) {
    cout << "Shared pointer ( " << obj.use_count() << " ) " << &obj;
    obj->print();
}

int main() {
    shared_ptr<MyClass> obj = make_shared<MyClass>(176);
    cout << "Shared pointer ( " << obj.use_count() << " ) " << &obj;
    obj->print();

    func(obj);

    cout << "Shared pointer ( " << obj.use_count() << " ) " << &obj;
    obj->print();
    return 0;
}