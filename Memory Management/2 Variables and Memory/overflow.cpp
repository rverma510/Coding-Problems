#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int id = 0;

void func(int &i) {
    int j = 1;
    cout << id++ << " " << &i << " " << &j << endl;
    func(i);
}

int main() {
    int i = 0;
    func(i);
    return 0;
}