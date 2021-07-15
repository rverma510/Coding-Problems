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

ll t, n, a, b;
string s;

void solve() {
    cin >> n >> a >> b;
    cin >> s;
    ll ones{0}, zeros{0};
    if (s[0] == '0') zeros++;
    else ones++;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            if (s[i] == '0') zeros++;
            else ones++;
        }
    }
    ll f;
    if (ones == zeros) f = zeros + 1;
    else if (ones > zeros) f = ones;
    else f = zeros;
    if (b >= 0) {
        cout << (n * (a + b)) << '\n';
    }
    else {
        cout << (n * a + f * b) << '\n';
    }
}

int main() {
    speed;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}