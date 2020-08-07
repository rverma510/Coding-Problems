#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> prod(n, 1);
    int tmp = arr[0];
    for (int i = 1; i < n; i++) {
        prod[i] *= tmp;
        tmp *= arr[i];
    }
    tmp = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        prod[i] *= tmp;
        tmp *= arr[i];
    }
    for (auto i: prod)
        cout << i << " ";
    cout << endl;
    return 0;
}