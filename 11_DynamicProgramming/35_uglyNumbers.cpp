#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int NMAX = 10005;
ll arr[10005];
void compute() {
    arr[0] = 0;
    arr[1] = 1;
    int i2, i3, i5;
    i2 = i3 = i5 = 1;
    for (int i = 2; i <= NMAX; i++) {
        arr[i] = min(arr[i2] * 2, min(arr[i3] * 3, arr[i5] * 5));
        if (arr[i] == arr[i2] * 2) {
            i2++;
        }
        if (arr[i] == arr[i3] * 3) {
            i3++;
        }
        if (arr[i] == arr[i5] * 5) {
            i5++;
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