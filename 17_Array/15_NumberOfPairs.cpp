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

int t, n, lft, rht;
int arr[maxn];


void solve() {
    cin >> n >> lft >> rht;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    ll ans = 0;
    for (int i = n - 1; i > 0; i--) {
        int l, r;
        if (arr[i] >= rht) continue;
        else if (arr[i] >= lft && arr[i] < rht) {
            l = 1;
            r = rht - arr[i];
        }
        else {
            l = lft - arr[i];
            r = rht - arr[i];
        }
        int lower = lower_bound(arr, arr + i, l) - arr;
        int upper = upper_bound(arr, arr + i, r) - arr;
        // cout << arr[i] << "  " << lower << "  " << upper << '\n';
        ans += upper - lower;
    }
    cout << ans << '\n';
}

int main() {
    speed;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*

4
3 4 7
5 1 2
5 5 8
5 1 2 4 3
4 100 1000
1 1 1 1
5 9 13
2 5 5 1 1

*/