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
const int maxn = 2e5 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int t, n, x;

void solve() {
    cin >> n >> x;
    ll sum{0}, mx{0};
    for (int tmp, i = 0; i < n; i++) {
        cin >> tmp;
        sum += tmp;
        mx += tmp / x;
        if (tmp % x != 0) mx++;
    }
    ll mn = sum / x;
    if (sum % x != 0) mn++; 
    cout << mn << ' ' << mx << endl;
}

int main() {
    speed;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}