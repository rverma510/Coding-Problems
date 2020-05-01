#include<bits/stdc++.h>
using namespace std;
int solveDP(string s1, string s2, int K){
    int m = s1.size();
    int n = s2.size();
    int dp[102][102][102], lcs[102][102];
    memset(dp, 0, sizeof(dp));
    memset(lcs, 0, sizeof(lcs));
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0){
                for(int k = 0; k <= K; k++)
                    dp[i][j][k] = 0;
                lcs[i][j] = 0;
            }
            else if(s1[i - 1] == s2[j - 1]){
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
                for(int k = 0; k <= lcs[i][j]; k++){
                    if(k == 0)
                        dp[i][j][k] = 0;
                    else
                        dp[i][j][k] = max(dp[i - 1][j - 1][k - 1] + (int)s1[i - 1], dp[i - 1][j - 1][k]);
                }
            }
            else{
                lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
                for(int k = 0; k <= lcs[i][j]; k++){
                    dp[i][j][k] = max(dp[i][j - 1][k], dp[i - 1][j][k]);
                }
            }
        }
    }
    if(lcs[m][n] < K)
        return 0;
    else
        return dp[m][n][K];

}
int main(){
    int t;
    cin>>t;
    while(t--){
    	string s1, s2;
        int k;
        cin>>s1>>s2;
        cin>>k;
        int ans = solveDP(s1, s2, k);
        if(ans != INT_MIN)
            cout<<ans<<endl;
        else
            cout<<0<<endl;    
    }
    
    return 0;
}