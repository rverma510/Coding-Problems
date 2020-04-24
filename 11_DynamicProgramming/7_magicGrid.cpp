#include<bits/stdc++.h>
using namespace std;
int solveMagicGrid(int **grid, int r, int c){
    int **dp = new int*[r];
    for(int i = 0; i < r; i++){
        dp[i] = new int[c];
    }
    dp[r - 1][c - 1] = grid[r - 1][c - 1] > 0 ? 1 : abs(grid[r - 1][c - 1] + 1);
    for(int i = r - 2; i >= 0; i--){
        dp[i][c - 1] = max(dp[i + 1][c - 1] - grid[i][c - 1], 1);
    }
    for(int i = c - 2; i >= 0; i--){
        dp[r - 1][i] = max(dp[r - 1][i + 1] - grid[r - 1][i], 1);
    }
    for(int i = r - 2; i >= 0; i--){
        for(int j = c - 2; j >= 0; j--){
            int x = min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = max(x - grid[i][j], 1);
        }
    }
    return dp[0][0];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int r, c;
        cin>>r>>c;
        int **grid = new int*[r];
        for(int i = 0; i < r; i++){
            grid[i] = new int[c];
            for(int j = 0; j < c; j++){
                cin>>grid[i][j];
            }
        }
        cout<<solveMagicGrid(grid, r, c)<<endl;
        for(int i = 0; i < r; i++){
            delete [] grid[i];
        }
        delete [] grid;
    }

    return 0;
}