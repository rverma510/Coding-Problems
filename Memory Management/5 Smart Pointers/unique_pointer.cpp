#include <iostream>
#include <memory>
int main() {
    std::unique_ptr<int> unique(new int);
    *unique = 10;
    std::cout << *unique << std::endl;
    return 0;
}