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
const int mx = 1e5 + 10, mod = 1e9 + 7; 
int n, t, _xor;

int main() {
    speed;
    cin >> n;
    _xor = 0;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        _xor ^= tmp;
    }
    if (!(n & 1) && _xor != 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if (n & 1)
        cout << n - 1 << "\n";
    else
        cout << n - 2 << "\n";
    for (int i = 0; i < n - 2; i += 2) {
        cout << i + 1<< " " << i + 2 << " " << i + 3 << "\n";
    }
    for (int i = 0; i < n - 2; i += 2) {
        cout << i + 1 << " " << i + 2 << " " << n << "\n";
    }
    return 0;
} 