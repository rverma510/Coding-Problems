#include <assert.h>

template<typename T>
T Product(T a, T b) {
    return a * b;
}
int main() { 
  assert(Product<int>(10, 2) == 20); 
}