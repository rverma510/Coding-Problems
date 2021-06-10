#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 30; i >= 0; i--) {
        int cnt = 0;
        ans ^= (1 << i);
        for (int j = 0; j < n; j++) {
            if ((ans & arr[j]) == ans) cnt++;
        }
        if (cnt < 2) ans ^= (1 << i);
    }
    cout << ans << '\n';
}