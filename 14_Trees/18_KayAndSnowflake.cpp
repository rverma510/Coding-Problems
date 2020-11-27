/*
    TODO:- Need to optimize time complexity
*/
#include <bits/stdc++.h>
using namespace std;

#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back

typedef long long ll;

const ll maxn = 1e6 + 10;

ll n, q;
vector<ll> children[maxn];
vector<ll> sizes(maxn);
vector<ll> dp(maxn, -1);

ll calculate_size(ll v) {
    if (children[v].size() == 0) {
        return sizes[v] = 1;
    }
    ll ans = 1;
    for (auto u: children[v]) {
        ans += calculate_size(u);
    }
    return sizes[v] = ans;
}

ll answer_query(ll root, ll v) {
    ll node = -1;
    for (auto u: children[v]) {
        if (2 * sizes[u] > sizes[root]) {
            node = u;
            break;
        }
    }
    if (node == -1) return v;
    return answer_query(root, node);
}

void solve() {
    cin >> n >> q;
    for (ll p, i = 1; i < n; i++) {
        cin >> p; p--;
        children[p].pb(i);
    }
    calculate_size(0);
    for (ll i = 0; i < n; i++) {
        dp[i] = answer_query(i, i) + 1;
    }
    for (ll v, node, i = 0; i < q; i++) {
        cin >> v; v--;
        cout << dp[v] << '\n';
    }   
}

int main() {
    speed;
    solve();
    return 0;
}