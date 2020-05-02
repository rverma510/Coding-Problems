/*
Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
Note: input data will be such so there will always be a solution.

Input Format :
Line 1 : String S of length N (1 <= N <= 1000)
Line 2 : String V of length M (1 <= M <= 1000)

Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V

Sample Input :
babab
babba

Sample Output :
3
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 10000005
int solveHelper(string S, string V, int m, int n, int **mem){
    if (m == 0) 
        return MAX;  
    if (n <= 0) 
        return 1;
    if(mem[m][n] != -1)
        return mem[m][n];   
    int k; 
    for (k=0; k < n; k++) 
        if (V[k] == S[0]) 
            break; 
    if (k == n) 
        return 1;
    int op1 = solveHelper(S.substr(1), V, m - 1, n, mem);
    int op2 = 1 + solveHelper(S.substr(1), V.substr(k + 1), m - 1, n - k - 1, mem);
    mem[m][n] = min(op1, op2);
    return mem[m][n];
}
int solve(string S, string V){
    int m = S.size();
    int n = V.size();
    int **mem = new int*[m + 1];
    for(int i = 0; i <= m; i++){
        mem[i] = new int[n + 1];
        for(int j = 0; j <= n; j++)
            mem[i][j] = -1;
    }
    return solveHelper(S, V, m, n, mem);
}
int main(){
	string S,V;
	cin>>S>>V;
	cout<<solve(S, V)<<endl;
	return 0;
}