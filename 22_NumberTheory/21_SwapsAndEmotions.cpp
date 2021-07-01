#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 10;

int power(int a, int b) {
    if (a == 0) return 0;
    ll res = 1;
    while(b) {
        if (b & 1) {
            res = (res * a) % mod;
        }
		a = (a * 1ll * a) % mod;
        b >>= 1;
    }
    return res;
}


int fact[maxn];
int factInv[maxn];
void calFact() {
    fact[0] = 1;
    fact[1] = 1;
    int i;
    for (i = 2; i < maxn; i++) {
        fact[i] = (i * 1ll * fact[i - 1]) % mod;
    }
    i--;
    factInv[i] = power(fact[i], mod - 2);
    for (i--; i >= 0; i--) {
        factInv[i] = (factInv[i + 1] * 1ll * (i + 1)) % mod;
    }
}

int ncr(int n, int r) {
    if (r < 0 || n < 0 || r > n) return 0;
    ll res = fact[n];
    res = (res * factInv[n - r]) % mod;
    res = (res * factInv[r]) % mod;
    return res;
}

int main() {
    calFact();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        ll res = ncr(n, k);
        res = (res * power(2, k)) % mod;
        cout << res << '\n';
    }
	return 0;
}