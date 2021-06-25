#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int euler[maxn];
void eulerPhi() {
    for (int i = 0; i < maxn; i++) {
        euler[i] = i;
    }
    for (int i = 2; i < maxn; i++) {
        if (euler[i] == i) {
            euler[i] = i - 1;
            for (int j = 2 * i; j < maxn; j += i) {
                euler[j] /= (i);
                euler[j] *= (i - 1);
            }
        }
    }
    for (int i = 1; i <= 10; i++) {
        cout << "The Euler Totient Phi for " << i << " is : " << euler[i] << '\n'; 
    }
}

int main() {
    eulerPhi();
    return 0;
}