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

ll t, n, x;
ll arr[maxn];
ll level[maxn];

void solve() {
    cin >> n >> x;
    ll ans = 0;
    ll idx = -1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ans += arr[i];
        int tmp = arr[i], l = 0;
        while (tmp % x == 0) tmp /= x, l++;
        level[i] = l;
        if (idx == -1 || level[idx] > level[i]) idx = i;
    }
    for (int i = 0; i < n; i++) {
        if (i < idx) level[i] = min(level[i], level[idx] + 1);
        else if (i > idx) level[i] = level[idx];
    }
    for (int i = 0; i < n; i++) {
        // cout << level[i] << ' ';
        while (level[i] > 0) {
            ans += arr[i];
            level[i]--;
        }
    }
    cout << ans << endl;
}

int main() {
    speed;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}