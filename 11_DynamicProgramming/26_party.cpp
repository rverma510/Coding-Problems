#include<bits/stdc++.h>
using namespace std;
int* solve(int *fee, int *fun, int n, int bud){
    if(n == 0){
        int *arr = new int[n];
        arr[0] = arr[1] = 0;
        return arr;
    }
    if(fee[n - 1] > bud){
        int *arr = solve(fee, fun, n - 1, bud);
        return arr;
    }
    else{
        int* arr1 = solve(fee, fun, n - 1, bud - fee[n - 1]);
        arr1[0] += fun[n - 1];
        arr1[1] += fee[n - 1];
        int *arr2 = solve(fee, fun, n - 1, bud);
        if(arr1[0] > arr2[0])
            return arr1;
        else
            return arr2;
    }
}
void solveDP(int *fee, int *fun, int n, int bud){
    int **dp = new int*[n + 1];
    for(int i = 0; i <= n; i++){
        dp[i] = new int[bud + 1];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= bud; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(fee[i] <= j){
                dp[i][j] = max(dp[i - 1][j], fun[i] + dp[i - 1][j - fee[i]]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int ans = bud;
    for(int i = 0; i < bud; i++){
        if(dp[n][i] == dp[n][bud]){
            ans = i;
            break;
        }
    }
    cout<<ans<<" "<<dp[n][bud]<<endl;
}
int main(){
    while(true){
        int bud, n;
        cin>>bud>>n;
        if(bud == 0 && n == 0)
            break;
        int *fee = new int[n + 1];
        int *fun = new int[n + 1];
        fee[0] = fun[0] = 0;
        for(int i = 0; i < n; i++)
            cin>>fee[i+1]>>fun[i+1];
        solveDP(fee, fun, n, bud);
        delete [] fee;
        delete [] fun;
    }
    return 0;
}