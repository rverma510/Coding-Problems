#include <iostream>
#include <stdlib.h>
using namespace std;
class MyClass {
    int num;
  public:
    MyClass() {
        cout << "Constructor called\n";
    }
    ~MyClass() {
        cout << "Destructor called\n";
    }
    void* operator new[](size_t size) {
        cout << "Allocating " << size << " bytes of memory\n";
        void *p = malloc(size);
        return p;
    }
    void operator delete[](void *p) {
        cout << "Deleting memory\n";
        free(p);
    }
};

int main() {
    MyClass *obj = new MyClass[3]();
    cout << "Obj array initialized\n";
    delete [] obj;
    return 0;
}