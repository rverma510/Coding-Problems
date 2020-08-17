#include <bits/stdc++.h>
using namespace std;

int recursiveLCS(string x, int m, string y, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (x[m - 1] == y[n - 1])
        return 1 + recursiveLCS(x, m - 1, y, n - 1);
    else
        return max(recursiveLCS(x, m - 1, y, n), recursiveLCS(x, m, y, n - 1));
}

int memoizedLCSHelper(string x, int m, string y, int n, vector<vector<int>> &mem) {
    if (m == 0 || n == 0)
        return 0;
    if (mem[m][n] != -1)
        return mem[m][n];
    if (x[m - 1] == y[n - 1])
        return mem[m][n] = 1 + memoizedLCSHelper(x, m - 1, y, n - 1, mem);
    else
        return mem[m][n] = max(memoizedLCSHelper(x, m - 1, y, n, mem), 
            memoizedLCSHelper(x, m, y, n - 1, mem));
}

int memoizedLCS(string x, string y) {
    int m = x.size();
    int n = y.size();
    vector<vector<int>> mem(m + 1, vector<int>(n + 1, -1));
    int ans = memoizedLCSHelper(x, m, y, n, mem);
    return ans;
}

int main() {
    string x, y;
    cin >> x >> y;
    // cout << recursiveLCS(x, x.size(), y, y.size()) << endl;
    cout << memoizedLCS(x, y) << endl;
    return 0;
}