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
const int maxn = 1e3 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ld scale = 1e6;

int t, n, m, k;
int arr1[maxn], arr2[maxn];

void solve() {
    cin >> k >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int j = 0; j < m; j++) cin >> arr2[j];
    bool flag = true;
    vector<int> res;
    int i = 0,j = 0;
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            if (arr1[i] == 0) {
                res.pb(arr1[i]);
                k++;
            }
            else if (arr1[i] <= k) {
                res.pb(arr1[i]);
            }
            else {
                flag = false;
                break;
            }
            i++;
        }
        else {
            if (arr2[j] == 0) {
                res.pb(arr2[j]);
                k++;
            }
            else if (arr2[j] <= k) {
                res.pb(arr2[j]);
            }
            else {
                flag = false;
                break;
            }
            j++;
        }
    }
    while (i < n && flag) {
        if (arr1[i] == 0) {
            res.pb(arr1[i]);
            k++;
        }
        else if (arr1[i] <= k) {
            res.pb(arr1[i]);
        }
        else {
            flag = false;
            break;
        }
        i++;
    }
    while (j < m && flag) {
        if (arr2[j] == 0) {
            res.pb(arr2[j]);
            k++;
        }
        else if (arr2[j] <= k) {
            res.pb(arr2[j]);
        }
        else {
            flag = false;
            break;
        }
        j++;
    }
    if (flag) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}

int main() {
    speed;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}