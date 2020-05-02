/*
Charlie acquired airline transport company and to stay in business he needs to lower the expenses by any means possible. There are N pilots working for his company 
(N is even) and N/2 plane crews needs to be made. A plane crew consists of two pilots - a captain and his assistant. A captain must be older than his assistant. 
Each pilot has a contract granting him two possible salaries - one as a captain and the other as an assistant. A captain's salary is larger than assistant's for 
the same pilot. However, it is possible that an assistant has larger salary than his captain. Write a program that will compute the minimal amount of money Charlie 
needs to give for the pilots' salaries if he decides to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in crews.

Input
The first line of input contains integer N, 2 ≤ N ≤ 10,000, N is even, the number of pilots working for the Charlie's company. The next N lines of input contain 
pilots' salaries. The lines are sorted by pilot's age, the salaries of the youngest pilot are given the first. Each of those N lines contains two integers separated 
by a space character, X i Y, 1 ≤ Y < X ≤ 100,000, a salary as a captain (X) and a salary as an assistant (Y).

Output
The first and only line of output should contain the minimal amount of money Charlie needs to give for the pilots' salaries. 

Sample Input
4 
5000 3000 
6000 2000 
8000 1000 
9000 6000 

Sample Output
19000 
*/
#include<bits/stdc++.h>
using namespace std;
int solve(int *cap, int *ast, int n, int x){
    if(x == 0 && n == 0)
        return 0;
    if(x == 0)
        return ast[0] + solve(cap + 1, ast + 1, n - 1, x + 1);
    if(x == n)
        return cap[0] + solve(cap + 1, ast + 1, n - 1, x - 1);
    else{
        return min(ast[0] + solve(cap + 1, ast + 1, n - 1, x + 1), cap[0] + solve(cap + 1, ast + 1, n - 1, x - 1));
    }
}
int solveMemHelper(int *cap, int *ast, int n, int x, int **mem){
    if(x == 0 && n == 0)
        return 0;
	if(mem[n][x] != -1)
    	return mem[n][x];
    if(x == 0)
        mem[n][x] = ast[0] + solveMemHelper(cap + 1, ast + 1, n - 1, x + 1, mem);
    else if(x == n)
        mem[n][x] = cap[0] + solveMemHelper(cap + 1, ast + 1, n - 1, x - 1, mem);
    else{
        int op1 = ast[0] + solveMemHelper(cap + 1, ast + 1, n - 1, x + 1, mem);
        int op2 = cap[0] + solveMemHelper(cap + 1, ast + 1, n - 1, x - 1, mem);
        mem[n][x] = min(op1, op2);
    }
    return mem[n][x];
}
int solveMem(int *cap, int *ast, int n, int x){
    int **mem = new int*[n + 1];
    for(int i = 0; i <= n; i++){
        mem[i] = new int[n / 2 + 1];
        for(int j = 0; j <= n / 2; j++){
           mem[i][j] = -1; 
        }
    }
    return solveMemHelper(cap, ast, n, x, mem);
}
int main(){
    int n;
    cin>>n;
    int *cap = new int[n];
    int *ast = new int[n];
    for(int i = 0; i < n; i++)
        cin>>cap[i]>>ast[i];
    cout<<solveMem(cap, ast, n, 0);
    return 0;
}