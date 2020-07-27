#include <iostream>
#include <memory>
using namespace std;
int main() {
    shared_ptr<int> shared(new int);
    cout << "Shared pointer count : " << shared.use_count() << endl;

    weak_ptr<int> weak1 = shared;
    weak_ptr<int> weak2 = weak1;
    cout << "Shared pointer count : " << shared.use_count() << endl;

    // weak_ptr<int> weak(new int)    COMPILE ERROR
    return 0;
}