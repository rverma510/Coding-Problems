/*
Sehwag has been solving a lot of mathematical problems recently. He was learning ETF (Euler 
Totient Function) and found the topic quite interesting. So, he tried solving a question on ETF. 
He will be given two numbers L and R. He has to find the probability that the ETF of a number in 
the range [L, R] is divisible by a number K.

Input:
The first line contains the number of test cases i.e. T.
The next T lines will contain three integers L, R and K.

Output:
Print the answer in a new line after rounding off the first 6 digits after the decimal place.

Constraints:
1 <= T <= 10
1 <= L <= R <= 10^12
0 <= R - L <= 10^5
1 <= K <= 10^6

Sample Input:
3
1 4 2
2 5 2
3 10 4

Sample Output:
0.500000
0.750000
0.375000
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 1e6 + 10;
bool prime[maxn];
int p[maxn], cnt{0};
void sieve() {
    memset(prime, true, maxn);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < maxn; i++) {
        if (prime[i]) {
            for (int j = i * i; j < maxn; j += i) {
                prime[j] = false;
            }
        }
    }
    p[cnt++] = 2;
    for (int i = 3; i < maxn; i += 2) {
        if (prime[i]) p[cnt++] = i;
    } 
    
}

int eulerPhi(ll l, ll r, int k) {
    ll euler[r - l + 1];
    ll num[r - l + 1];
    for (ll i = l; i <= r; i++) {
        euler[i - l] = i;
        num[i - l] = i;
    }
    for (int i = 0; i < cnt; i++) {
        ll base = (l / p[i]) * p[i];
        if (base < l) {
            base += p[i];
        }
        for (ll j = base; j <= r; j += p[i]) {
            while (!(num[j - l] % p[i])) num[j - l] /= p[i];
            euler[j - l] -= euler[j - l] / p[i];
        }
    }
    for (ll i = l; i <= r; i++) {
        if (num[i - l] > 1) {
            euler[i - l] -= euler[i - l] / num[i - l]; 
        }
    }
    int c = 0;
    for (ll i = l; i <= r; i++) {
        if (!(euler[i - l] % k)) c++;
    }
    return c++;
}

int main() {
	sieve();
    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        int k;
        cin >> l >> r >> k;
        if (k == 1) {
            cout << 1 << '\n';
            continue;
        }
        double c = eulerPhi(l, r, k);
        cout << fixed << setprecision(6) << c / (r - l + 1) << '\n';
    }
    return 0;
}