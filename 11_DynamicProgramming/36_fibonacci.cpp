#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int NMAX = 1005;
ll arr[1005];

void compute() {
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < NMAX; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
        arr[i] %= 1000000007;
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