#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int n;
vector<pll> arr;

bool compare(const pll &a, const pll &b) {
    if (a.first < b.first) return true;
    else if (a.first > b.first) return false;
    else return a.second <= b.second;
}

int main() {
    cin >> n;
    for (int x, y, i = 0; i < n; i++) {
        cin >> x >> y;
        arr.push_back({x, y});
    }
    sort(arr.begin(), arr.end());
    ll a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        a = max(a, arr[i].second - arr[i].first);
        if (i + 1 < n && arr[i].second >= arr[i + 1].first) {
            arr[i + 1].first = arr[i].first;
            arr[i + 1].second = max(arr[i + 1].second, arr[i].second);
        }
        if (i + 1 < n) b = max(b, arr[i + 1].first - arr[i].second);
    }
    cout << a << ' ' << b << endl;
    return 0;
}