#include <iostream>
#include <stdlib.h>
using namespace std;

class MyClass {
    int *num;
  public:
    MyClass() {
        cout << "Allovate Memory\n";
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

    // MyClass *obj = (MyClass*)malloc(sizeof(MyClass));
    // obj->setNumber(3); // EXC_BAD_EXCESS
    // free(obj);

    MyClass *obj1 = new MyClass();
    obj1->setNumber(5);
    delete obj1;

    return 0;
}