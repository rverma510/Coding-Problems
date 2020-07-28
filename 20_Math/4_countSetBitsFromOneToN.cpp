#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n) {
    int ans = 0;
    int i = 0;
    while ((1 << i) <= n) {
        int k = 0;
        int change = 1 << i;
        for (int j = 0; j <= n; j++) {
            ans += k;
            if (change == 1) {
                k = !k;
                change = 1 << i;
            }
            else {
                change--;
            }
        }
        i++;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << countSetBits(n) << endl;
    return 0;
}