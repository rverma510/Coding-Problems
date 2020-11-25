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
const int maxn = 5e3 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};


int t, n;
vector<pii> arr(maxn);

bool compare(const pii &a, const pii &b) {
    if (a.fi != b.fi) {
        return a.fi < b.fi;
    }
    else {
        return a.se < b.se;
    }
}

int main() {
    speed;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        arr[i] = mp(a, b);
    }
    sort(arr.begin(), arr.begin() + n);
    int ans = min(arr[0].fi, arr[0].se);
    for (int i = 1; i < n; i++) {
        if (ans <= arr[i].se) ans = arr[i].se;
        else ans = arr[i].fi;
    }
    cout << ans << "\n";
    return 0;
}