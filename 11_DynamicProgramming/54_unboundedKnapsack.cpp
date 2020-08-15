#include <bits/stdc++.h>
using namespace std;

int recursiveKnapsack(vector<int> &w, vector<int> &val, int n, int W) {
    if (n == 0 || W == 0)
        return 0;
    if (w[n - 1] > W)
        return recursiveKnapsack(w, val, n - 1, W);
    else
        return max(val[n - 1] + recursiveKnapsack(w, val, n, W - w[n - 1]), recursiveKnapsack(w, val, n - 1, W));
}

int main() {
    int n, W;
    cin >> n;
    vector<int> w(n), val(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    cin >> W;
    cout << recursiveKnapsack(w, val, n, W) << endl;
    return 0;
}