#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;
bool prime[maxn];
int prime_fac[maxn];
map<int, vector<int>> m;
void sieve() {
    memset(prime, true, maxn);
    prime[0] = prime[1] = false;
    prime_fac[0] = prime_fac[1] = 0;
    for (int i = 2; i < maxn; i++) {
        if (prime[i]) {
            prime_fac[i] = 1;
            for (int j = 2 * i; j < maxn; j += i) {
                prime[j] = false;
                prime_fac[j]++;
            }
        }
    }
    for (int i = 1; i < maxn; i++) {
        m[prime_fac[i]].push_back(i);
    }
}

int main(){
    sieve();
    int t;
    cin >> t;
    while (t--) {
        int a, b, n;
        cin >> a >> b >> n;
        if (m.find(n) == m.end()) {
            cout << 0 << '\n';
            continue;
        }
        vector<int> &arr = m[n];
        int low = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
        int up = upper_bound(arr.begin(), arr.end(), b) - arr.begin();
        cout << (up - low) << '\n';
    }
	return 0;
}