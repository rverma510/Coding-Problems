#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);
#define rf freopen("input.txt", "r", stdin);
#define wf freopen("output.txt", "w", stdout);
using namespace std;
typedef pair<double, int> pdi;
const int mx = 1e5 + 10, mod = 1e9 + 7;

int t, n, k;
int arr[mx];
double dp[mx];
int helper[mx];
priority_queue<pdi> pq;

int main() {
    speed;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0] = log(arr[0]);
    helper[0] = arr[0];
    pq.push({-dp[0], 0});
    for (int i = 1; i < n; i++) {
        while (i - pq.top().second > k) pq.pop();
        dp[i] = dp[pq.top().second] + log(arr[i]);
        helper[i] = (1ll * helper[pq.top().second] * arr[i]) % mod; 
        pq.push({-dp[i], i});
    }
    cout << helper[n - 1] << "\n";
    return 0;
}
