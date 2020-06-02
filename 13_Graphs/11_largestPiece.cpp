#include<iostream>
#include<vector>
using namespace std;
#define NMAX 55
char cake[NMAX][NMAX];
int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int visited[51][51] = {false};
void solveHelper(int n, char cake[NMAX][NMAX], int i, int j, int &cnt) {
    cnt++;
    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int newI = i + arr[k][0];
        int newJ = j + arr[k][1];
        if (newI < 0 || newI >= n || newJ < 0 || newJ >= n)
            continue;
    	if (!visited[newI][newJ] && cake[newI][newJ] == '1')
            solveHelper(n, cake, newI, newJ, cnt);
    }
}
int solve(int n,char cake[NMAX][NMAX]) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && cake[i][j] == '1'){
                int cnt = 0;
                solveHelper(n, cake, i, j, cnt);
                ans = max(ans, cnt);
            }
        }
    }
	return ans;
}
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}