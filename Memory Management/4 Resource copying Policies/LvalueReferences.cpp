// An lvalue reference can be considered as an alternative name for an object. 
// It is a reference that binds to an lvalue.
#include <iostream>

int main() {
    int i = 1;
    int &j = i;
    i++;
    j++;
    std::cout << "i = " << i << ", j = " << j << std::endl;
    return 0;
}