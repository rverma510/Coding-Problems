// creating a deadlock
#include <iostream>
#include <memory>
class MyClass {
  public:
    std::shared_ptr<MyClass> _member;    
    ~MyClass() {
        std::cout << "Destructor called\n";
    }
};

int main() {
    std::shared_ptr<MyClass> shared1(new MyClass());
    std::shared_ptr<MyClass> shared2(new MyClass());
    shared1->_member = shared2;
    shared2->_member = shared1;

    return 0;  
}