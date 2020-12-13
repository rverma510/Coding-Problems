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
const int maxn = 1e5 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n;
int arr[maxn];
int l[maxn];
int r[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    l[0] = 1;
    for (int i = 1; i < n; i++) {
        l[i] = 1;
        if (arr[i] > arr[i - 1]) l[i] += l[i - 1];
    }
    r[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        r[i] = 1;
        if(arr[i] < arr[i + 1]) r[i] += r[i + 1];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, 1 + r[i + 1]);
        ans = max(ans, 1 + l[i - 1]);
        if (i != 0 && i != n - 1 && arr[i + 1] - arr[i - 1] > 1) 
            ans = max(ans, l[i - 1] + 1 + r[i + 1]);
    }
    if (ans > n) ans = n;
    cout << ans << endl;

}

int main() {
    speed;
    solve();
    return 0;
}