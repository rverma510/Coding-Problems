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

int n, m;
map<int, int> _m;
int a[maxn];
int s[maxn];

void solve() {
    cin >> n;
    for (int tmp, i = 0; i < n; i++) {
        cin >> tmp;
        _m[tmp]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> s[i];
    int mx_a = 0, mx_s = 0;
    int ans = -1;
    for (int i = 0; i < m; i++) {
        if (_m.find(a[i]) != _m.end()) {
            if (mx_a < _m[a[i]]) {
                ans = i;
                mx_a = _m[a[i]];
                if (_m.find(s[i]) != _m.end()) mx_s = _m[s[i]];
            }
            else if (mx_a == _m[a[i]]) {
                if (_m.find(s[i]) != _m.end() && mx_s < _m[s[i]]) {
                    ans = i;
                    mx_s = _m[s[i]];
                } 
            }
        }
        else if (mx_a == 0 && _m.find(s[i]) != _m.end()) {
            if (mx_s < _m[s[i]]) {
                mx_s = _m[s[i]];
                ans = i;
            }
        }
    }
    if (ans == -1) cout << 1 << endl;
    else cout << ans + 1 << endl;
}

int main() {
    speed;
    solve();
    return 0;
}