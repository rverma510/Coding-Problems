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

ll n;

void solve() {
    cin >> n;
    vector<ll> children[n];
    vector<ll> c(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> c[i];
        if (x != -1) {
            --x;
            children[x].pb(i);
        }
    }
    vector<ll> ans;
    for (ll i = 0; i < n; i++) {
        if (c[i] == 1) {
            bool pos = 1;
            for (ll x: children[i]) {
                if (c[x] == 0) {
                    pos = 0;
                    break;
                }
            }
            if (pos) {
                ans.pb(i + 1);
            }
        }
    }
    if (ans.size() > 0) {
        for (auto x: ans) cout << x << ' ';
    }
    else {
        cout << -1;
    }   
    cout << endl;
}

int main() {
    speed;
    solve();
    return 0;
}