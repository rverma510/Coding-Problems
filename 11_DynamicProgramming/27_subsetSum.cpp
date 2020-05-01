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
    bool **dp = new bool*[n + 1];
    for(int i = 0; i <= n; i++)
        dp[i] = new bool[sum + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            if(i == 0 && j > 0)
                dp[i][j] = false;
        	else if(j == 0)
                dp[i][j] = true;
            else if(input[i] <= j){
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - input[i]];
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
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