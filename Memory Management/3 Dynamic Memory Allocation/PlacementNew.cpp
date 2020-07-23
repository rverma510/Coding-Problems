#include <iostream>
#include <stdlib.h>
using namespace std;

class MyClass {
    int *num;
  public:
    MyClass() {
        cout << "Allocate Memory\n";
        num = (int*)malloc(sizeof(int));
    }
    ~MyClass() {
        cout << "Destructor called\n";
        free(num);
    }
    void setNumber(int n) {
        *num = n;
        cout << "Number : " << *num << endl;
    }
};

int main() {
    void *memory = malloc(sizeof(MyClass));
    MyClass *obj = new (memory) MyClass();
    
    cout << memory << "  " << obj << "\n";

    obj->setNumber(50);
    
    obj->~MyClass();
    free(memory);
}