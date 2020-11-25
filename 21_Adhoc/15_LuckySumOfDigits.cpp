#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    int ans = INT_MAX;
    int a = -1, b = -1;
    for (int i = 0; i <= n / 7; i++) {
        if ((n - i * 7) % 4 == 0) {
            int tmp = i + (n - i * 7) / 4;
            if (ans > tmp) {
                ans = tmp;
                a = (n - i * 7) / 4;
                b = i;
            }
        }
    }
    if (a == -1) {
        cout << -1 << '\n';
    }
    else {
        for (int i = 0; i < a; i++) {
            cout << '4';
        }
        for (int i = 0; i < b; i++) {
            cout << '7';
        }
        cout << '\n';
    }
    return 0;
}