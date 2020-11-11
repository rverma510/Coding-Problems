#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);
#define rf freopen("input.txt", "r", stdin);
#define wf freopen("output.txt", "w", stdout);
using namespace std;

const int mx = 55;
int t, n, k;
int arr[mx];
long long binom[mx][mx];

void compute_binom() {
    for (int i = 0; i < mx; i++) {
        binom[0][i] = 0;
        binom[i][i] = 1;
        binom[i][0] = 1;
    }
    for (int i = 1; i < mx; i++) {
        for (int j = 1; j < i; j++) {
            binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
        }
    }
}

int main() {
    speed;
    compute_binom();
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int m = 0, r = 0;
        int val = arr[k - 1];
        for (int i = 0; i < n; i++) {
            if (i < k && arr[i] == val)
                r++;
            if (arr[i] == val)
                m++;
        }
        cout << binom[m][r] << "\n";
    }
    return 0;
}
