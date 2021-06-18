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

int t, n;
int arr[maxn];


void solve() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum % n != 0) {
        cout << -1 << '\n';
        return;
    }
    sum /= n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > sum) cnt++;
    }
    cout << cnt << '\n';
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

5
4
4 5 2 5
2
0 4
5
10 8 5 1 4
1
10000
7
1 1 1 1 1 1 1


*/