#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
    int n = arr.size();
    if (n <= 1)
        return 0;
    int profit = 0;
    int i = 0;
    while (i < n - 1) {
        while (i < n - 1 && arr[i] >= arr[i + 1])
            i++;
        if (i == n - 1)
            break;  
        int buy = i++;
        while (i < n && arr[i] >= arr[i - 1] )
            i++;
        int sell = i - 1;
        profit += arr[sell] - arr[buy];
    }
    return profit;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxProfit(arr) << endl;
    return 0;
}