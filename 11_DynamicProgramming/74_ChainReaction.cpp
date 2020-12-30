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

int n;
int a[maxn], b[maxn];
int dp[maxn];

void solve() {
    cin >> n;
    for (int a, i = 0; i < n; i++) {
        cin >> a;
        cin >> b[a];
    }
    priority_queue<pii> pq;
    if (b[0] > 0) dp[0] = 1;
    int mx = 0;
    for (int i = 1; i < maxn; i++) {
        if (b[i] == 0) dp[i] = dp[i - 1];
        else {
            if (b[i] >= i) dp[i] = 1;
            else dp[i] = dp[i - b[i] - 1] + 1;
        }
        mx = max(dp[i], mx);
    }
    cout << n - mx << endl;
}

int main() {
    speed;
    solve();
    return 0;
}
