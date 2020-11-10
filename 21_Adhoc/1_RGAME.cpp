#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll func(vector<ll> &arr, ll i, ll left, ll right) {
    if (i >= arr.size())
        return 0;
    ll ans1 = ((ll)pow(2, arr.size() - i - 1) * right * arr[i]) + func(arr, i + 1, left, arr[i]);
    ll ans2 = ((ll)pow(2, arr.size() - i - 1) * left * arr[i]) + func(arr, i + 1, arr[i], right);
    return (ans1 + ans2);
}
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n + 1);
        for (int i = 0; i <= n; i++) {
            cin >> arr[i];
        }
        cout << func(arr, 1, arr[0], arr[0]) << "\n";
    }
    return 0;
}