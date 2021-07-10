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
typedef pair<ll, pll> plll;
const int mod = 1e9 + 7;
 
const double pi = acos(-1.0);
const int maxn = 2e5 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
 
ll n, k, x, cnt{0};
ll arr[maxn];
 
// priority_queue<plll, vector<plll>, greater<plll>> pq;
priority_queue<ll, vector<ll>, greater<ll>> pq;
 
void solve() {
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i - 1] > x) {
            cnt++;
            pq.push(arr[i] - arr[i - 1] - 1);
        }
    }
    cnt++;
    while (!pq.empty() && k) {
        ll tmp  = pq.top() / x; pq.pop();
        if (tmp > k) break;
        k -= tmp;
        cnt--;
        
    }
    cout << cnt << '\n';
}
 
int main() {
    speed;
    solve();
    return 0;
}