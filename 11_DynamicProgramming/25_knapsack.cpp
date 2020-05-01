/*
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. 
What is the maximum value V, that thief can take ?
Space complexity should be O(W).

Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry

Output Format :
Line 1 : Maximum value V

Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100

Sample Input 1 :
4
1 2 4 5
5 4 8 6
5

Sample Output :
13
*/
#include<bits/stdc++.h>
using namespace std;
int knapsack(int* weights, int* values, int n, int maxWeight){
    if(maxWeight == 0 || n == 0)
        return 0;
    if(weights[n - 1] > maxWeight)
        return knapsack(weights, values, n - 1, maxWeight);
    else
        return max(values[n - 1] + knapsack(weights, values, n - 1, maxWeight - weights[n - 1]), knapsack(weights, values, n - 1, maxWeight));
}
int knapsackMem(int *weights, int *values, int n, int maxWeight, int **mem){
    if(maxWeight == 0 || n == 0)
        return 0;
    if(mem[n - 1][maxWeight] != -1)
        return mem[n - 1][maxWeight];
    if(weights[n - 1] > maxWeight)
        mem[n - 1][maxWeight] =  knapsackMem(weights, values, n - 1, maxWeight, mem);
    else
        mem[n - 1][maxWeight] =  max(values[n - 1] + knapsackMem(weights, values, n - 1, maxWeight - weights[n - 1], mem), knapsackMem(weights, values, n - 1, maxWeight, mem));
    return mem[n - 1][maxWeight];
}
int knapsackDP(int *weights, int *values, int n, int maxWeight){
    int **dp = new int*[n + 1];
    for(int i = 0; i <= n; i++)
        dp[i] = new int[maxWeight + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= maxWeight; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(weights[i - 1] <= j){
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int ans = dp[n][maxWeight];
    for(int i = 0; i <= n; i++)
        delete [] dp[i];
    delete [] dp;
    return ans;
}
int knapsackDPOpt(int *weights, int *values, int n, int maxWeight){
    int *dp = new int[maxWeight + 1];
    for(int i = 0; i <= maxWeight; i++)
        dp[i] = 0;
    for(int i = 0; i < n; i++){
        for(int j = maxWeight; j >= weights[i]; j--){
            dp[j] = max(dp[j], values[i] + dp[j - weights[i]]);
        }
    }
    int ans = dp[maxWeight];
    delete [] dp;
    return ans;
}
int main(){
    int n; 
    cin >> n;
    int* weights = new int[n];
    int* values = new int[n];
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }
    for(int i = 0; i < n; i++){
        cin >> values[i];
    }
    int maxWeight;
    cin >> maxWeight;
    // cout << knapsack(weights, values, n, maxWeight);
    // int **mem = new int*[n];
    // for(int i = 0; i < n; i++){
    //     mem[i] = new int[maxWeight + 1];
    //     for(int j = 0; j <= maxWeight; j++)
    //         mem[i][j] = -1;
    // }
    // cout << knapsackMem(weights, values, n, maxWeight, mem);
    // for(int i = 0; i < n; i++)
    //     delete [] mem[i];
    // delete [] mem;
    // cout << knapsackDP(weights, values, n, maxWeight);
    cout << knapsackDPOpt(weights, values, n, maxWeight);
    return 0;
}


