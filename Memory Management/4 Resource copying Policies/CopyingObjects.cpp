#include <iostream>
#include <stdlib.h>
using namespace std;

class MyClass {
    int *num;
  public:
    MyClass() {
        num = (int*)malloc(sizeof(int));
    }
    ~MyClass() {
        free(num);
    }
    void printOwnAddress() {
        cout << "Own Address    : " << this << endl;
    } 
    void printMemberAddress() {
        cout << "Member Address : " << num << endl;
    }
};

int main() {
    MyClass obj1;
    obj1.printOwnAddress();
    obj1.printMemberAddress();

    MyClass obj2(obj1);
    obj2.printOwnAddress();
    obj2.printMemberAddress();
}

/*

Own Address    : 0x7ffc8a357558
Member Address : 0x5556cfc47eb0
Own Address    : 0x7ffc8a357560
Member Address : 0x5556cfc47eb0
free(): double free detected in tcache 2
Aborted (core dumped)

*/