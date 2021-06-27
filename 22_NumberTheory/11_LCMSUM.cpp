#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int maxn = 1e6 + 10;
ll euler[maxn];
void eulerPhi() {
    for (int i = 0; i < maxn; i++) euler[i] = i;
    
    for (int i = 2; i < maxn; i++) {
    	if (euler[i] == i) {
            euler[i]--;
            for (int j = 2 * i; j < maxn; j += i) {
                euler[j] /= i;
                euler[j] *= (i - 1);
            }
        }
    }
}

int main()
{
    eulerPhi();
    ll n; cin >> n;
    ll sum = 1;
    for (int i = 1; i <= sqrt(n); i++) {
        if (!(n % i)) {
            sum += i * euler[i];
            if ((n / i) == i) continue;
            sum += (n / i) * euler[n / i];
        }
    }
    sum = (n * 1ll * sum) / 2;
    cout << sum << '\n';
}
