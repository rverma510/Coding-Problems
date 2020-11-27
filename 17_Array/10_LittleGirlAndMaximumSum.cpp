#include <bits/stdc++.h>
using namespace std;

#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

typedef long long ll;

const ll maxn = 1e6 + 10;

ll n, q;

void solve() {
    cin >> n >> q;
    vector<ll> arr(n);
    vector<ll> pos(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }
    for (int l, r, i = 0; i < q; i++) {
        cin >> l >> r; l--; r--;
        pos[l]++;
        if (r < n - 1) pos[r + 1]--;
    }
    for (int i = 1; i < n; i++) {
        pos[i] += pos[i - 1];
    }
    sort(arr.begin(), arr.end());
    sort(pos.begin(), pos.end());
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans += arr[i] * pos[i];
    }
    cout << ans << endl;
}

int main() {
    speed;
    solve();
    return 0;
}