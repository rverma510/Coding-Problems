#include<bits/stdc++.h>
using namespace std;
#define MAXN 102
int arr[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
char str[11] = {'C', 'O', 'D', 'I', 'N', 'G', 'N', 'I', 'N', 'J', 'A'};
bool visited[101][101] = {false};
int solveHelper(char Graph[][MAXN], int N, int M, int i, int j, int idx) {
    if (idx == 11) 
        return 1;
	visited[i][j] = true;
    int ans = 0;
    for (int k = 0; k < 8; k++) {
        int newI = i + arr[k][0];
        int newJ = j + arr[k][1];
        if (newI < 0 || newI >= N || newJ < 0 || newJ >= M)
            continue;
        if (!visited[newI][newJ] && Graph[newI][newJ] == str[idx])
            ans = ans | solveHelper(Graph, N, M, newI, newJ, idx + 1);
        if (ans)
            break;
    }	
    visited[i][j] = false;
    return ans;
}
int solve(char Graph[][MAXN],int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Graph[i][j] == 'C') {
                int ans = solveHelper(Graph, N, M, i, j, 1);
                if (ans == 1)
                	return 1;
            }
        }
    }
    return 0;
}
int main() {
	int N,M,i;
	char Graph[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++) {
		cin>>Graph[i];
	}
	cout<<solve(Graph,N,M)<<endl;
}