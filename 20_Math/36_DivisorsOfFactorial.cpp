/*
Divisors Of Factorial

Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.

Input
The first line contains T, number of testcases.
T lines follows each containing the number N.

Output
Print T lines of output each containing the answer.

Constraints
1 <= T <= 500
0 <= N <= 50000

Sample Input:
3
2
3
4

Sample Output:
2
4
8

N = p1^a . p2^b . ... . pn ^ k
Divisors = (a + 1).(b + 1). ... .(k + 1)

*/

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

const int maxn = 50000;
bool isPrime[maxn];
int p[maxn];
int cnt{0};
void sieve() {
    memset(isPrime, true, maxn);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < maxn; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < maxn; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i < maxn; i++) {
        if (isPrime[i]) {
            p[cnt++] = i;
        }
    }
}
int main(){
    sieve();
    int t;
	cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 0 || n == 1) {
            cout << 1 << '\n';
            continue;
        }
        int ans = 1;
        for (int i = 0; i < cnt; i++) {
            int tmp = p[i];
            if (tmp > n) break;
            int c = 0;
            while (true) {
                if (n / tmp == 0) break;
                c += n / tmp;
                tmp *= p[i];
            }
            ans = (ans * 1ll * (c + 1)) % mod;
        }
        cout << ans << '\n';
    }
	return 0;
}