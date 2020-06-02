#include<bits/stdc++.h>
using namespace std;
#define MAXN 51
int arr[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool visited[51][51] = {false};
int ans = 0;
void solveHelper(char board[][MAXN], int n, int m, int i, int j, int fromI, int fromJ, char ch) {
    if (i < 0 || i >= n || j < 0 || j >= m)
    	return;
    if (board[i][j] != ch)
        return;
    if(visited[i][j]) {
        ans = 1;
        return;
    }
    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int newI = i + arr[k][0];
        int newJ = j + arr[k][1];
        if (newI == fromI && newJ == fromJ)
            continue;
        solveHelper(board, n, m, newI, newJ, i, j, ch);
    }
}
int solve(char board[][MAXN],int n, int m) {
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                solveHelper(board, n, m, i, j, -1, -1, board[i][j]);
            }
        }
    }
    return ans;
}
int main() {
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}