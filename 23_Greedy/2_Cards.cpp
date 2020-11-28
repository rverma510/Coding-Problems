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
const int maxn = 1e2 + 10;

ll t, n;
vector<pii> arr(maxn);

void solve() {
    cin >> n;
    for (int tmp, i = 0; i < n; i++) {
        cin >> tmp;
        arr[i] = mp(tmp, i + 1);
    }
    sort(arr.begin(), arr.begin() + n);
    ll l = 0, r = n - 1;
    while (l <= r) {
        cout << arr[l].se << ' ' << arr[r].se << endl;
        l++; r--;
    }
}

int main() {
    speed;
    solve();
    return 0;
}