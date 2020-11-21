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
const int maxn = 1e3 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n;
int h[maxn], s[maxn];

int main() {
    speed;
    int x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int dp[2][x + 1];
    int k = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (i == 0 || j == 0) {
                dp[k][j] = 0;
            }
            else if (h[i - 1] > j) {
                dp[k][j] = dp[k ^ 1][j];
            }
            else {
                dp[k][j] = max(dp[k ^ 1][j], s[i - 1] + dp[k ^ 1][j - h[i - 1]]);
            }
        }
        k ^= 1;
    }
    cout << dp[k ^ 1][x] << endl;
    return 0;
}