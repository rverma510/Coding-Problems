#include <iostream>

void func(int &i) {
    std::cout << "i = " << i << std::endl;
}

int main() {
    int j = 42;
    func(j);

    // func(42); // cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    
    int k = 23;
    // func(j + k); // cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’

    int i = j + k;
    int &&l = j + k; // rvalue reference
    std::cout << "i = " << i << ", l = " << l << std::endl;

    return 0;
}