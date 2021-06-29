#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;

int power(int a, int b, int p) {
    if (a == 0) return 0;
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % p;
        }
        a = (a * 1ll * a) % p;
        b >>= 1;
    }
    return res;
}

int main() {
	int t;
    cin >> t;
    while (t--) {
        int p, n;
        cin >> n >> p;
        if (n >= p) {
            cout << 0 << '\n';
            continue;
        }
        ll res = 1;
        for (int i = n + 1; i < p; i++) {
            res = res * power(i, p - 2, p) % p;
        }
        res = res % p;
        res = (-res + p);
        cout << res << '\n';
    }
    return 0;
}