#include<bits/stdc++.h>
using namespace std;

countWaysToMakeChange(int den[], int n, int value){
    if(value == 0)
        return 1;
    if(n <= 0 || value < 0)
        return 0;
    return countWaysToMakeChange(den, n, value - den[n - 1]) + countWaysToMakeChange(den, n - 1, value);
}

countWaysToMakeChangeItr(int den[], int n, int value){
    int dp[value + 1][n];
    for(int i = 0; i < n; i++)
        dp[0][i] = 1;
    for(int i = 1; i <= value; i++){
        for(int j = 0; j < n; j++){
            int x = (i - den[j]) >= 0 ? dp[i - den[j]][j] : 0;
            int y = (j >= 1) ? dp[i][j - 1] : 0;
            dp[i][j] = x + y;
        }
    }
    return dp[value][n - 1];
}

int main(){
  int n;
  cin>>n;
  int* den = new int[n];
  for(int i = 0; i < n; i++){
    cin>>den[i];
  }
  int value;
  cin>>value;
  cout<<countWaysToMakeChangeItr(den, n, value);
  return 0;
}