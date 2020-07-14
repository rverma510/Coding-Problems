#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll NMAX = 105;
ll arr[105];

void compute() {
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < NMAX; i++) {
        arr[i] = 0;
        for (int j = 0; j < i; j++) {
            arr[i] += arr[j] * arr[i - j - 1];
        }
    }
}

int main() {
    compute();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << arr[n] << endl;
    }
    return 0;
}