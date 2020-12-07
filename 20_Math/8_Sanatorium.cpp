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

ll arr[maxn];

void solve() {
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    arr[1] -= arr[0];
    arr[2] -= arr[0];
    ll res;
    if (arr[2] == 0) res = 0;
    else if (arr[1] == arr[2]) res = (2ll * arr[2] - arr[1] - 1ll);
    else res = (2ll * arr[2] - arr[1] - 2ll);
    cout << res << endl;
}

int main() {
    speed;
    solve();
    return 0;
}