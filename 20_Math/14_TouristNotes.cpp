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

int n, m;
vector<pii> arr;

void solve() {
    cin >> n >> m;
    for (int x, y, i = 0; i < m; i++) {
        cin >> x >> y;
        arr.pb({x, y});
    }
    int ans = arr[0].se + arr[0].fi - 1;
    ans = max(ans, arr[m - 1].se + n - arr[m - 1].fi);
    for (int i = 0; i < m - 1; i++) {
        int tmp1 = arr[i + 1].fi - arr[i].fi;
        int tmp2 = abs(arr[i + 1].se - arr[i].se);
        int l = min(arr[i].se, arr[i + 1].se);
        if (tmp1 < tmp2) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        tmp1--;
        if ((tmp1 + tmp2) & 1) ans = max(ans, l + (tmp1 + tmp2) / 2 + 1);
        else ans = max(ans, l + (tmp1 + tmp2) / 2);
    }
    cout << ans << endl;
}

int main() {
    speed;
    solve();
    return 0;
}