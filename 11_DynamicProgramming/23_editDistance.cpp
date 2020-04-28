#include<bits/stdc++.h>
using namespace std;
int editDistance(string s1, string s2){
    if(s1.size() == 0 || s2.size() == 0)
        return 0;
    if(s1[0] == s2[0])
        return editDistance(s1.substr(1), s2.substr(1));
    else{
        int op1  = editDistance(s1.substr(1), s2);
        int op2 = editDistance(s1.substr(1), s2.substr(1));
        int op3  = editDistance(s1, s2.substr(1));
        return 1 + min(op1, min(op2, op3));
    }
}
int editDistanceDP(string s1, string s2){
    int m = s1.size();
    int n = s2.size();
    int **dp = new int*[m + 1];
    for(int i = 0; i <= m; i++)
        dp[i] = new int[n + 1];
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
        }
    }
    return dp[m][n];
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    cout<<editDistanceDP(s1, s2)<<endl;
    return 0;
}