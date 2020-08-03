#include <iostream>
#include <thread>
using namespace std;
int main() {
    unsigned int nCores = thread::hardware_concurrency();
    cout << "The machine has " << nCores << " cores\n";
    return 0;
}