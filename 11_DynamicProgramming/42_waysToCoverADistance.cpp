#include <iostream>
#include <vector>
using namespace std;
 
int recursiveWay(int n) {
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    return recursiveWay(n - 1) + 
            recursiveWay(n - 2) + 
            recursiveWay(n - 3);
}

int  memoizedWayHelper(int n, int *arr) {
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (arr[n] != -1)
        return arr[n];
    arr[n] = memoizedWayHelper(n - 1, arr) +
            memoizedWayHelper(n - 2, arr) +
            memoizedWayHelper(n - 3, arr);
    return arr[n];
}

int memoizedWay(int n) {
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
        arr[i] = -1;
    int ans = memoizedWayHelper(n, arr);
    delete [] arr;
    return ans;
}

int dynamicWay(int n) {
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] +
                dp[i - 2] + 
                dp[i - 3];
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    // cout << recursiveWay(n) << endl;
    // cout << memoizedWay(n) << endl;
    cout << dynamicWay(n) << endl;
    return 0;
}