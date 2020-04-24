#include<bits/stdc++.h>
using namespace std;
int solveProblem(int **grid, int m, int n){
    int **sumGrid = new int*[m + 1];
    for(int i = 0; i <= m; i++){
        sumGrid[i] = new int[n + 1];
    }
    for(int i = 0; i <= m; i++){
        sumGrid[i][n] = 0;
    }
    for(int j = 0; j <= n; j++){
        sumGrid[m][j] = 0;
    }
    for(int i = m - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            sumGrid[i][j] = grid[i][j] + sumGrid[i + 1][j];
        }
    }
    for(int j = n - 1; j >= 0; j--){
        for(int i = m - 1; i >= 0; i--){
            sumGrid[i][j] = sumGrid[i][j] + sumGrid[i][j + 1];
        }
    }
    int mx = INT_MIN;
    for(int si = 0; si < m; si++){
        for(int sj = 0; sj < n; sj++){
            for(int ei = si + 1; ei <= m; ei++){
                for(int ej = sj + 1; ej <= n; ej++){
                    int ans = sumGrid[si][sj] - sumGrid[ei][sj] - sumGrid[si][ej] + sumGrid[ei][ej];
                    mx = max(mx, ans); 
                }
            }
        }
    }
    return mx;
}
int kadane(int *dp, int size){
    int curr = 0;
    int mx = INT_MIN;
    for(int i = 0; i < size; i++){
        curr = max(dp[i], curr + dp[i]);
    	mx = max(mx, curr);    
    }
    return mx;
}
int solveProblemDP(int **grid, int m, int n){
    int mx = INT_MIN;
    for(int l = 0; l < n; l++){
        int *dp = new int[m];
        for(int i = 0; i < m; i++){
            dp[i] = 0;
        }
        for(int r = l; r < n; r++){
            for(int i = 0; i < m; i++){
                dp[i] += grid[i][r];
            }
            int ans = kadane(dp, m);
            mx = max(mx, ans);
        }
    }
    return mx;
}
int main(){
    int m, n;
    cin>>m>>n;
    int **grid = new int*[m];
    for(int i = 0; i < m; i++){
        grid[i] = new int[n];
        for(int j = 0; j < n; j++){
            cin>>grid[i][j];
        }
    }
    cout<<solveProblemDP(grid, m, n)<<endl;
    return 0;
}