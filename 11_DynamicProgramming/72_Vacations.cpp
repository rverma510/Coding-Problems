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
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n;
int arr[maxn];
map<pii, int> _m;

int func_rest(int n, int i) {
    if (n == 0) return 0;
    if (_m.find({n, i}) != _m.end()) return _m[{n, i}];
    int ans;
    if (arr[n - 1] == 0) ans = 1 + func_rest(n - 1, 0);
    else if (arr[n - 1] == 1 && i != 1) ans = func_rest(n - 1, 1);
    else if (arr[n - 1] == 2 && i != 2) ans = func_rest(n - 1, 2);
    else if (arr[n - 1] == 3) {
        if (i == 1) ans = func_rest(n - 1, 2);
        else if (i == 2) ans = func_rest(n - 1, 1);
        else ans = min(func_rest(n - 1, 1), func_rest(n - 1, 2)); 
    }
    else ans = 1 + func_rest(n - 1, 0);
    return _m[{n, i}] = ans;
}

void solve() {
    cin >> n;
    // for (int i = 0; i < n; i++) cin >> arr[i];
    // cout << func_rest(n, 0) << endl;
    int tmp, a = 0, d = 0;
    while (n--) {
        tmp = a;
        cin >> a;
        if (a == tmp && a != 3) 
            a = 0;
        if (a != tmp && a == 3)
            a -= tmp;
        if (a == 0) d++;
    }
    cout << d << endl;
}

int main() {
    speed;
    solve();
    return 0;
}