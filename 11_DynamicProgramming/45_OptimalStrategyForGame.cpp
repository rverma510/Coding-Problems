#include <iostream>
#include <vector>
using namespace std;

int memoizedStrategyHelper(vector<int> &arr, int i, int j, vector<vector<int>> &memo) {
    if (i + 1 == j)
        return max(arr[i], arr[j]);
    if (memo[i][j] != -1)
        return memo[i][j];  
    return memo[i][j] =  max(arr[i] + 
                                    min(memoizedStrategyHelper(arr, i + 2, j, memo), 
                                    memoizedStrategyHelper(arr, i + 1, j - 1, memo)),
                            arr[j] + 
                                    min(memoizedStrategyHelper(arr, i + 1, j - 1, memo), 
                                    memoizedStrategyHelper(arr, i, j -2, memo)));
}

int memoizedStrategy(vector<int> &arr, int i, int j) {
    int n = arr.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    int ans = memoizedStrategyHelper(arr, i, j, memo);
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << memoizedStrategy(arr, 0, n - 1) << endl;
    return 0;
}