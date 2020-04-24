#include<bits/stdc++.h>
using namespace std;

int getMaxMoney(int arr[], int n){
    if(n <= 0)
        return 0;
    int ans1 = arr[n - 1] + getMaxMoney(arr, n - 2);
    int ans2 = getMaxMoney(arr, n - 1);
    return max(ans1, ans2);
}

int getMaxMoneyDP(int arr[], int n){
    if(n == 1)
        return arr[0];
    if(n == 2)
        return max(arr[0], arr[1]);
    int *dp = new int[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for(int i = 2; i < n; i++){
        int ans1 = dp[i - 2] + arr[i];
        int ans2 = dp[i - 1];
        dp[i] = max(ans1, ans2);
    }
    return dp[n - 1];
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<getMaxMoneyDP(arr, n)<<endl;
    delete [] arr;
    return 0;
}