#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);
#define rf freopen("in.txt", "r", stdin);
#define wf freopen("out.txt", "w", stdout);
using namespace std;

typedef long long ll;
const int mx = 1e4 + 10;
int n, t;
int a[mx];
int new_a[mx], new_b[mx];

int main() {
    speed;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << "Case 1:\n";
        for (int i = 0; i < n; i++) {
            int ans = 0;
            for (int j = 0; j < 16; j++) {
                if (a[i] & (1 << j)) {
                    ans += (1 << j);
                }
            }
            cout << ans << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << (a[i] >> 16) << " ";
        }
        cout << "\n";
    }
    return 0;
}