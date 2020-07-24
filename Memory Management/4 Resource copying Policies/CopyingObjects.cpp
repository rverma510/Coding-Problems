/*
The default behavior of both copy constructor and assignment operator is to perform a shallow copy.
Fortunately, in C++, the copying process can be controlled by defining a tailored copy constructor 
as well as a copy assignment operator. The copying process must be closely linked to the respective 
resource release mechanism and is often referred to as copy-ownership policy. Tailoring the copy 
constructor according to your memory management policy is an important choice that we often need to 
make when designing a class. There are several well-known copy-ownership policies.
*/
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