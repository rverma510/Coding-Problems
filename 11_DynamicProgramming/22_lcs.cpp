#include<bits/stdc++.h>
using namespace std;

int lcs(char *s1, char *s2){
    if(s1[0] == '\0' || s2[0] == '\0')
        return 0;
    if(s1[0] == s2[0])
        return 1 + lcs(s1, s2);
    return max(lcs(s1 + 1, s2), lcs(s1, s2 + 1));
}

int lcsMem(char *s1, char *s2, int m, int n, int **mem){
    if(m == 0 || n == 0)
        return 0;
    if(mem[m][n] != -1)
        return mem[m][n];
    if(s1[0] == s2[0]){
        mem[m][n] = 1 + lcsMem(s1 + 1, s2 + 1, m - 1, n - 1, mem);
        return mem[m][n];
    }
    else{
        int op1 = lcsMem(s1 + 1, s2, m - 1, n, mem);
        int op2 = lcsMem(s1, s2 + 1, m, n - 1, mem);
        mem[m][n] = max(op1, op2);
        return mem[m][n]; 
    }
}
string lcsDP(char *s1, char *s2){
    int m = strlen(s1);
    int n = strlen(s2);
    if(m == 0 || n == 0)
        return "";
    int **dp = new int*[m + 1];
    for(int i = 0; i<= m; i++){
        dp[i]  = new int[n + 1];
    }
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string sub = "";
    int i = m, j = n;
    while(i > 0 && j > 0){
        if(s1[i - 1] == s2[j - 1]){
            sub = s1[i - 1] + sub;
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    return sub;
}
int main(){
    char a[100],b[100];
    cin>>a>>b;
    // int m = strlen(a);
    // int n = strlen(b);
    // int **mem = new int*[m + 1];
    // for(int i = 0; i <= m; i++){
    //     mem[i] = new int[n + 1];
    //     for(int j = 0; j <= n; j++)
    //         mem[i][j] = -1;
    // }
    // cout<<lcsMem(a, b, m, n, mem)<<endl;
    cout<<lcsDP(a, b)<<endl;
    return 0;
}