#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007;
int countBST(int n){
    long *dp = new long[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = 0;
       for(int k = 1; k <= i; k++){
           dp[i] += dp[k - 1] * dp[i - k];
           dp[i] %= mod;
        }
        dp[i] %= mod;
    }
    int ans = dp[n];
    delete [] dp;
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<countBST(n)<<endl;
    return 0;
}