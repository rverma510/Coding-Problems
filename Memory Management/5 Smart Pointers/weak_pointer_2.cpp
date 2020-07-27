#include <iostream>
#include <memory>
using namespace std;

int main() {
    shared_ptr<int> shared(new int);
    weak_ptr<int> weak(shared);

    shared.reset(new int);
    if (weak.expired()) {
        cout << "Weak pointer expired.\n";
    }
    return 0;
}