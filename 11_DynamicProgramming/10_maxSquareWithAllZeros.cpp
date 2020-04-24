#include<bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int **dp = new int*[row + 1];
    for(int i = 0; i <= row; i++){
        dp[i] = new int[col + 1];
        for(int j = 0; j <= col; j++)
            dp[i][j] = 0;
    }
    int mx = 0;
    for(int i = row - 1; i >= 0; i--){
        for(int j = col - 1; j >= 0; j--){
            if(arr[i][j] == 1)
                dp[i][j] = 0;
            else{
            	dp[i][j] += 1 + min(dp[i][j + 1], min(dp[i + 1][j + 1], dp[i + 1][j]));
        		if(mx < dp[i][j])
                	mx = dp[i][j];    
        	}
            
        }
    }
    for(int i = 0; i <= row; i++)
        delete [] dp[i];
    delete [] dp;
    return mx;
}
int main()
 {
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
}