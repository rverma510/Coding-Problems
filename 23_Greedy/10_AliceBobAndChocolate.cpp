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

ll n;
int arr[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int l = 0, r = n - 1;
    int lc = 0, rc = 0;
    while (l < r) {
        if (lc <= rc) {
            lc += arr[l];
            arr[l] = -1;
            l++;
        }
        else {
            rc += arr[r];
            arr[r] = -1;
            r--;
        }
    }
    if (arr[l] != -1) {
        if (lc <= rc) {
            l++;
            r++;
        }
    }
    cout << l << ' ' << n - r << endl; 
}

int main() {
    speed;
    solve();
    return 0;
}