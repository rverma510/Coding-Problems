#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int > pii;
const int maxn = 1001;

int n, m;
int amount_for_price[maxn]{0};

int main() {
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    cin >> n >> m;
    for (int x, y, i = 0; i < m; i++) {
        cin >> x >> y;
        amount_for_price[x] += y;
    }
    ll ans = 0;
    for (int i = 0; i < maxn; i++) {
        if (!amount_for_price[i]) continue; 
        if (n >= amount_for_price[i]) {
            ans += i * amount_for_price[i];
            n -= amount_for_price[i];
        }
        else {
            ans += n * i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}