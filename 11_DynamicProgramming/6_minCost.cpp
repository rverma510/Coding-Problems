#include<bits/stdc++.h>
using namespace std;
int minCost(int **input, int si, int sj, int ei, int ej){
    if(si == ei && sj == ej)
        return input[si][sj];
    if(si > ei || sj > ej)
        return INT_MAX;
    int ans = INT_MAX;
    ans = min(ans, minCost(input, si, sj + 1, ei, ej));
    ans = min(ans, minCost(input, si + 1, sj + 1, ei, ej));
    ans = min(ans, minCost(input, si + 1, sj, ei, ej));  
    return ans + input[si][sj];
}
int minCostMem(int **input, int si, int sj, int ei, int ej, int **output){
    if(si == ei && sj == ej)
        return input[si][sj];
    if(si > ei || sj > ej)
        return INT_MAX;
    if(output[si][sj] != -1)
        return output[si][sj];
    int ans = INT_MAX;
    ans = min(ans, minCost(input, si, sj + 1, ei, ej));
    ans = min(ans, minCost(input, si + 1, sj + 1, ei, ej));
    ans = min(ans, minCost(input, si + 1, sj, ei, ej));  
    output[si][sj] = ans + input[si][sj];
    return output[si][sj];
}
int minCostDP(int **input, int m, int n){
    int **dp = new int*[m];
    for(int i = 0; i < m; i++){
        dp[i] = new int[n];
    }
    dp[m - 1][n - 1] = input[m - 1][n - 1];
    for(int i = m - 2; i >= 0; i--){
        dp[i][n -1] = dp[i + 1][n - 1] + input[i][n - 1];
    }
    for(int i = n - 2; i >= 0; i--){
        dp[m - 1][i] = dp[m - 1][i + 1] + input[m - 1][i];
    }
    for(int i = m - 2; i >= 0; i--){
        for(int j = n - 2; j >= 0; j--){
            dp[i][j] = input[i][j] + min(dp[i][j + 1], min(dp[i + 1][j + 1], dp[i + 1][j]));
        }
    }
    return dp[0][0];
}
int main(){
    int **input = new int*[3];
    input[0] = new int[3];
    input[1] = new int[3];
    input[2] = new int[3]; 
    input[0][0] = 4;
    input[0][1] = 2;
    input[0][2] = 2;
    input[1][0] = 1;
    input[1][1] = 8;
    input[1][2] = 3;
    input[2][0] = 1;
    input[2][1] = 1;
    input[2][2] = 8;
    int **output = new int*[3];
    for(int i = 0; i < 3; i++){
        output[i] = new int[3];
        for(int j = 0; j < 3; j++)
            output[i][j] = -1;
    } 
    // cout<<minCostMem(input, 0, 0, 2, 2, output)<<endl;
    cout<<minCostDP(input, 3, 3)<<endl;
    delete [] input[0];
    delete [] input[1];
    delete [] input[2];
    delete [] input;
    delete [] output[0];
    delete [] output[1];
    delete [] output[2];
    delete [] output;
    return 0;
}