#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int maxn = 1e5 + 10;
bool prime[maxn];
int p[maxn];
int cnt{0};
void sieve() {
    memset(prime, true, maxn);
    for (int i = 2; i * i < maxn; i++) {
        if (prime[i]) {
            for (int j = i * i; j < maxn; j += i) {
                prime[j] = false;
            }
        }
    }
    
    for (int i = 2; i < maxn; i++) {
        if (prime[i]) p[cnt++] = i;
    }
}

void segSieve(ll l, ll r) {
    bool segPrime[r - l + 1];
    memset(segPrime, true, r - l + 1);
    for (int i = 0; i < cnt; i++) {
        if (p[i] > sqrt(r) + 1) break;
        ll base = (l / p[i]) * p[i];
        if (base < l) {
            base += p[i];
        }
        for (ll j = base; j <= r; j += p[i]) {
            segPrime[j - l] = false;
        }
        if (base == p[i]) {
            segPrime[base - l] = true;
        }
    }
    for (int i = 0; i <= r - l; i++) {
        if (segPrime[i]) {
            cout << i + l << '\n';
        }
    }
}

int main()
{
    sieve();
    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        segSieve(l, r);
    }
	return 0;
}