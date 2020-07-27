#include <iostream>
#include <memory>
#include <string>

class MyClass {
  private:
    std::string _text;
  public:
    MyClass() {}
    MyClass(std::string t): _text(t) {}
    ~MyClass() {
        std::cout << "Destructor called " << _text << std::endl;
    }
    void setText(std::string t) { _text = t;}
};

int main() {
    std::unique_ptr<MyClass> myClass1(new MyClass());
    std::unique_ptr<MyClass> myClass2(new MyClass("String 2"));

    myClass1->setText("String 1");
    *myClass1 = *myClass2;

    std::cout << "Object has stack addresses : " << &myClass1 << " and " << &myClass2 << std::endl;
    std::cout << "Object has heap addresses : " << myClass1.get() << " and " << myClass2.get() << std::endl;

    return 0;
}