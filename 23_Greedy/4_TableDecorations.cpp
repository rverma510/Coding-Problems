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
const int maxn = 2e5 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

ll arr[3];
ll sum;

void solve() {
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + 3);
    if (arr[2] > (2 * (arr[0] + arr[1]))) {
        cout << (arr[0] + arr[1]) << endl;
    }
    else cout << sum / 3 << endl;
}

int main() {
    speed;
    solve();
    return 0;
}