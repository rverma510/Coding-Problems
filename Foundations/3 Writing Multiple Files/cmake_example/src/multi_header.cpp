#include <vector>
#include <iostream>
#include "increment_and_sum.h"
using std::vector;
using std::cout;

int main() {
    vector<int> v{1, 2, 3, 4};
    int total = IncrementAndComputeVectorSum(v);
    cout << "The total is: " << total << "\n";
    return 0;
}

// build
// g++ -std=c++17 ./multi_header.cpp ./increment_and_sum.cpp ./vect_add_one.cpp
// run
// ./a.exe