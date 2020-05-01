#include<bits/stdc++.h>
using namespace std;
bool solve(int *input, int n, int sum){
    if(sum == 0)
        return true;
    if(sum > 0 && n == 0)
        return false;
    if(input[n - 1] > sum)
        return solve(input, n - 1, sum);
    else
        return solve(input, n - 1, sum) || solve(input, n - 1, sum - input[n - 1]);
}
bool solveDP(int *input, int n, int sum){
    bool **dp = new bool*[2];
    for(int i = 0; i <= 1; i++)
        dp[i] = new bool[sum + 1];
    for(int i = 0; i <= sum; i++)
        dp[0][i] = false;
    dp[0][0] = true;
    int flag = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            dp[flag][j] = dp[flag ^ 1][j];
            if(j >= input[i])
                dp[flag][j] = dp[flag][j] || dp[flag ^ 1][j - input[i]];
        }
        flag = flag ^ 1;
    }
    return dp[flag ^ 1][sum];
}
int main(){
    int n, sum;
    cin>>n;
    int *input = new int[n + 1];
    input[0] = 0;
    for(int i = 0; i < n; i++)
        cin>>input[i + 1];
    cin>>sum;
    if(solveDP(input, n, sum))
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}