#include <iostream>
#include <vector>
using namespace std;

int recursivePartition(vector<int> &v, int i, int part1, int part2) {
    if (i == 0)
        return abs(part1 - part2);
    else
        return min(recursivePartition(v, i - 1, part1 + v[i - 1], part2 - v[i - 1]),
                recursivePartition(v, i - 1, part1, part2));
}

int dynamicPartition(vector<int> &v) {
    int n = v.size();
    int sum = 0;
    for (auto i: v) {
        sum += i;
    }
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i - 1])
                dp[i][j] |= dp[i - 1][j - v[i - 1]];
        }
    }
    int diff = 1e8;
    for (int i = sum / 2; i >= 0; i--) {
        if (dp[n][i])
            diff = min(diff, sum - i * 2);
    }
    return diff;
} 

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    // cout << recursivePartition(v, n, 0, sum) << endl;
    cout << dynamicPartition(v) << endl;
    return 0;
}