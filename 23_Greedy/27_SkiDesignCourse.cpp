#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int arr[1010];

int main() {
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll ans = 1e18;
    for (int i = 0; i <= 83; i++) {
        ll cost = 0;
        for (int j = 0; j < n; j++) {
            int tmp;
            if (arr[j] < i) tmp = i - arr[j];
            else if (arr[j] > i + 17) tmp = arr[j] - i - 17;
            else tmp = 0;
            cost += tmp * tmp;
        }
        ans = min(ans, cost);
    }
    cout << ans << '\n';
    return 0;
}