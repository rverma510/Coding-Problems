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
const int maxn = 3;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n, k, d;
ll dp[110][2];

ll find_path(int sum, bool pres) {
    if (sum < 0) return 0;
    if (sum == 0) {
        if (pres) return 1;
        else return 0;
    }
    if (dp[sum][pres] != -1) return dp[sum][pres]; 
    ll ans = 0;
    for (int i = 1; i <= k; i++) {
        if (i >= d) ans += find_path(sum - i, true);
        else ans += find_path(sum - i, pres);
    }
    return dp[sum][pres] = ans % mod;
}

void solve() {
    cin >> n >> k >> d;
    mem(dp, -1);
    cout << find_path(n, false);
}

int main() {
    speed;
    solve();
    return 0;
}