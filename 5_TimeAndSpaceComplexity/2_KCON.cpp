#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll kadane(ll *arr, int n){
    ll currentMax = 0;
    ll bestMax = INT_MIN;
    for(int i=0;i<n;i++){
        currentMax += arr[i];
        if(currentMax > bestMax)
            bestMax = currentMax;
        if(currentMax < 0)
            currentMax = 0;
    }
    return bestMax;
}

ll maxSubArraySum(ll *arr, int n, int k){

    ll kadaneSum = kadane(arr, n);
    if(k == 1)
        return kadaneSum;
    ll currPreSum = 0, currSufSum = 0;
    ll maxPreSum = INT_MIN, maxSufSum = INT_MIN;

    for(int i=0;i<n;i++){
        currPreSum += arr[i];
        maxPreSum = max(currPreSum, maxPreSum);
    }

    ll totSum = currPreSum;

    for(int i=n-1;i>=0;i--){
        currSufSum += arr[i];
        maxSufSum = max(currSufSum, maxSufSum);
    }

    ll ans;
    if(totSum >= 0){
        ans = max(maxPreSum + maxSufSum + (k-2) * totSum, kadaneSum);
    }
    else{
        ans = max(maxPreSum + maxSufSum, kadaneSum);
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        ll *arr = new ll[n];
        for(int i=0;i<n;i++)
            cin>>arr[i]; 
        cout<<maxSubArraySum(arr, n, k)<<"\n";
    }
    return 0;
}