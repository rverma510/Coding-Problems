// reset a shared pointer
#include <iostream>
#include <memory>
class MyClass {
  public:
    ~MyClass() {
        std::cout << "Destructor called\n";
    }
};

int main() {
    std::shared_ptr<MyClass> shared1(new MyClass());
    std::cout << "Shared pointer count " << shared1.use_count() << std::endl;

    shared1.reset(new MyClass());
    std::cout << "Shared pointer count " << shared1.use_count() << std::endl;

    return 0;  
}