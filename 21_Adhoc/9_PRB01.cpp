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
const int mx = 1e5 + 10;
int t, n;
bool prims[mx];
void compute_prims() {
    memset(prims, true, sizeof(prims));
    prims[0] = false;
    prims[1] = false;
    for (int i = 2; i < mx; i++) {
        if (prims[i]) {
            for (int j = i + i; j < mx; j += i) {
                prims[j] = false;
            }
        }
    }
}
int main() {
    speed;
    compute_prims();
    cin >> t;
    while (t--) {
        cin >> n;
        if (prims[n])
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}