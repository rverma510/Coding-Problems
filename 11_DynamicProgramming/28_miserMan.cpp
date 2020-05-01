/*
Jack is a wise and miser man. Always tries to save his money.
One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses
numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B
following these conditions:
1. At every city, he has to change the bus.
2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
You are to help Jack to go from A to B by spending the minimum amount of money.
N, M, K <= 100.

Input
Line 1:    N M

Line 2:    NxM Grid

Each row lists the fares the M busses to go form the current city to the next city.

Output
Single Line containing the minimum amount of fare that Jack has to give.

Sample Input
5 5
1  3  1  2  6
10 2  5  4  15
10 9  6  7  1
2  7  1  5  3
8  2  6  1  9

Sample Output
10
*/
#include<bits/stdc++.h>
using namespace std;
int solveHelper(int **grid, int n, int m, int index){
    if(n == 0)
        return 0;
    int temp = index;
    if(index - 1 >= 0 && grid[n - 1][index - 1] < grid[n - 1][index])
        temp = index - 1;
    if(index + 1 < m && grid[n - 1][index + 1] < grid[n - 1][index])
        temp = index + 1;
    return grid[n - 1][temp] + solveHelper(grid, n - 1, m, temp);
}
int solve(int **grid, int n, int m){
    if(n == 0)
        return 0;
    int ans = INT_MAX;
    for(int i = 0; i < m; i++){
        int temp = grid[n - 1][i] + solveHelper(grid, n - 1, m, i);
        ans = min(ans, temp);
    }
    return ans;
}
int solveDP(int **grid, int n, int m){
    if(n == 0)
        return 0;
    int **dp = new int*[n];
    for(int i = 0; i < n; i++){
        dp[i] = new int[m];
    }
    for(int i = 0; i < m; i++)
        dp[0][i] = grid[0][i];
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            int mn = dp[i - 1][j];
            if(j - 1 >= 0)
                mn = min(mn, dp[i - 1][j - 1]);
            if(j + 1 < m)
                mn = min(mn, dp[i - 1][j + 1]);
            dp[i][j] = grid[i][j] + mn;
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < m; i++){
        ans = min(ans, dp[n - 1][i]);
    }
    return ans;
}
int main(){
    int n, m;
    cin>>n>>m;
    int **grid = new int*[n];
    for(int i = 0; i < n; i++){
        grid[i] = new int[m];
        for(int j = 0; j < m; j++)
            cin>>grid[i][j];
    }
    cout<<solveDP(grid, n, m)<<endl;
    return 0;
}