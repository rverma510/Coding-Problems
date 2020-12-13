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
const int maxn = 5e2 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n, l;
int arr[maxn][maxn];

void solve() {
    cin >> n >> l;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l - 1; j++) {
            arr[i][j] = cnt;
            cnt++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = l - 1; j < n; j++) {
            if (j == l - 1) ans += cnt;
            arr[i][j] = cnt;
            cnt++;
        }
    }
    cout << ans << endl;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    speed;
    solve();
    return 0;
}