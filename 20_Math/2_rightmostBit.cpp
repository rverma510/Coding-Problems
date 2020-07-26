#include <iostream>
using namespace std;

int getRightmostbit(int n) {
    for (int i = 0; i <= 31; i++) {
        if (n & (1 << i))
            return i + 1;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    cout << getRightmostbit(n) << endl;
    return 0;
}