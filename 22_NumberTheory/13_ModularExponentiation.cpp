#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int mod = 1e9 + 7;
int modularExp(int a, int b) {
    if (a == 0) return 0;
    if (b == 1) return a;
    ll ans;
    if (!(b % 2)) {
        ll smallAns = modularExp(a, b / 2);
        ans = (smallAns * smallAns) % mod;
    }
    else {
        ll smallAns = modularExp(a, b - 1);
        ans = a % mod;  
        ans = (ans * smallAns) % mod;
    }
    return int((ans + mod) % mod);

}

int iterativeModularExp(int a, int b) {
    if (a == 0) return 0;
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % mod;
        }
        a = (a * 1ll * a) % mod;
        b >>= 1;
    }
    return int((ans + mod) % mod);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << modularExp(a, b) << '\n';
    cout << iterativeModularExp(a, b) << '\n';
    return 0;
}
