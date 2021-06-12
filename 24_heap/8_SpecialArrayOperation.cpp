#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// int main() {
//     int n, q, k;
//     ll sum = 0;
//     multiset<int> s;
//     multiset<int>::iterator it;
//     vector<ll> res;
//     cin >> n >> q;
//     for (int x, i = 0; i < n; i++) {
//         cin >> x;
//         sum += x;
//         s.insert(x);
//     }
//     res.push_back(sum);
//     for (int i = 1; i < n; i++) {
//         it = s.begin();
//         int mn = *it;
//         s.erase(it);
//         it = s.end();
//         it--;
//         int mx = *it;
//         s.erase(it);
//         int r = mx - mn;
//         sum = sum - mx - mn + r;
//         res.push_back(sum);
//         s.insert(r);
//     }
//     for (int i = 0; i < q; i++) {
//         cin >> k;
//         cout << res[k] << '\n';
//     }
//     return 0;
// }

int main() {
    int n, q, k;
    ll sum = 0;
    cin >> n >> q;
    vector<int> arr(n);
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        max_pq.push(arr[i]);
        min_pq.push(arr[i]);
    }
    vector<ll> result(n);
    result[0] = sum;
    for (int i = 1; i < n; i++) {
        int mn = min_pq.top(); min_pq.pop();
        int mx = max_pq.top(); max_pq.pop();
        int res = mx - mn;
        result[i] = result[i - 1] - mx - mn + res;
        min_pq.push(res);
        max_pq.push(res);
    }
    for (int i = 0; i < q; i++) {
        cin >> k;
        cout << result[k] << '\n';
    }
    return 0;
}