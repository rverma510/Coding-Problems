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
const int maxn = 5e2 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int c[3], n[3], p[3];
string s;
ll r;

void solve() {
    getline(cin, s);
    for (auto i: s) {
        if (i == 'B') c[0]++;
        else if (i == 'S') c[1]++;
        else c[2]++;
    }
    cin >> n[0] >> n[1] >> n[2];
    cin >> p[0] >> p[1] >> p[2];
    cin >> r;
    ll l = 0, h = 2e12;
    ll ans = 0;
    while (l <= h) {
        ll m = l + (h - l) / 2;
        ll tmp = max(0ll, c[0] * m - n[0]) * p[0] + max(0ll, c[1] * m - n[1]) * p[1] + max(0ll, c[2] * m - n[2]) * p[2];
        if (tmp <= r) {
            ans = max(ans, m);
            l = m + 1;
        }
        else {
            h = m - 1;
        }
    }
    cout << ans << endl; 
}

int main() {
    speed;
    solve();
    return 0;
}