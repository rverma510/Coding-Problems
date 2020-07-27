#include <iostream>
#include <memory>
using namespace std;
int main() {
    // creating a unique pointer
    unique_ptr<int> unique(new int);

    // creating a shared pointer from unique pointer
    shared_ptr<int> shared1 = move(unique);

    // creating a shared pointer from weak pointer using lock
    weak_ptr<int> weak(shared1);
    shared_ptr<int> shared2 = weak.lock();

    // creating a raw pointer from shared (or unique) pointer
    int *p = shared2.get();
    //delete p;  CANNOT DELETE RESOURCE

    return 0;  
}