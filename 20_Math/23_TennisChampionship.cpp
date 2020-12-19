#include <bits/stdc++.h>
using namespace std;

#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define rf freopen("in.txt", "r", stdin);
#define wf freopen("out.txt", "w", stdout);

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define mem(a, b) memset(a, b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7;

const double pi = acos(-1.0);
const int maxn = 1e6 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

ll f[maxn];
void fib() {
    f[0] = 1;
    f[1] = 2;
    for (int i = 2; i < maxn; i++) {
        f[i] = f[i - 1] + f[i - 2]; 
    }
}

ll n;

void solve() {
    cin >> n;
    if (n == 2) {
        cout << 1 << endl;
        return;
    }
    else if (n == 3) {
        cout << 2 << endl;
        return;
    }
    ll ans = 2;
    n -= 3;
    while (n >= f[ans - 1]) {
        n -= f[ans - 1];
        ans++;
    }
    cout << ans << endl;
}

int main() {
    speed;
    fib();
    solve();
    return 0;
}