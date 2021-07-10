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
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7;

const double pi = acos(-1.0);
const int maxn = 1e6 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ld scale = 1e6;

int t;
string s;

void solve() {
    cin >> s;
    int dp[2][2];
    mem(dp, -1);
    ll ans = 0;
    for (int i = 0; i < s.size(); i++) {
        int j = i - 1;
        int p = i & 1;
        if (s[i] != '1') j = min(j, max(dp[0][p ^ 1], dp[1][p]));
        if (s[i] != '0') j = min(j, max(dp[0][p], dp[1][p ^ 1]));
        ans += i - j;
        if (s[i] != '?') dp[s[i] - '0'][p] = i;
    }
    cout << ans << '\n';
}

int main() {
    speed; 
    cin >> t; char ch; cin.get(ch);
    while (t--) {
        solve();
    }
    return 0;
}