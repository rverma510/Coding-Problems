#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &arr, int m) {
    int n = arr.size();
    if (n <= 1)
        return 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int i = 0;
    while (i < n - 1) {
        while (i < n - 1 && arr[i] >= arr[i + 1])
            i++;
        int buy = i++;
        if (i == n - 1)
            break;
        while (i < n && arr[i] >= arr[i - 1])
            i++;
        int sell = i - 1;
        if (pq.size() < m)
            pq.push(arr[sell] - arr[buy]);
        else if (pq.top() < arr[sell] - arr[buy]) {
            pq.pop();
            pq.push(arr[sell] - arr[buy]);
        }
    } 
    int profit = 0;
    while (!pq.empty()) {
        profit += pq.top();
        pq.pop();
    }
    return profit;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> arr(n);
    for (int i= 0; i < n; i++)
        cin >> arr[i];
    cin >> m;
    cout << maximumProfit(arr, m) << endl;
    return 0;
}