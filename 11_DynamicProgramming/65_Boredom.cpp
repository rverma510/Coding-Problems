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

int t, n;

int main() {
    speed;
    cin >> n;
    int mx = INT_MIN;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        m[tmp]++;
        mx = max(mx, tmp);
    }
    vector<ll> dp(mx + 1);
    dp[0] = 0;
    dp[1] = m.find(1) != m.end() ? m[1] : 0;
    for (int i = 2; i <= mx; i++) {
        dp[i] = dp[i - 1];
        if (m.find(i) != m.end()) {
            dp[i] = max(dp[i], dp[i - 2] + (i * 1ll * m[i]));
        }
    }
    cout << dp[mx] << endl;
    return 0;
}