#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, l, r;
    cin >> n;
    vector<int> arr(n, 0);
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        arr[l - 1]++;
        if (r < n)
            arr[r]--;
        for (int j = 0; j < n; j++) 
            cout << arr[j] << " ";
        cout << endl;
    }
    cout << arr[0] << " ";
    for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
        cout << arr[i] << " ";
    }
    cout << endl;

}