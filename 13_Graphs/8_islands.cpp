#include<bits/stdc++.h>
using namespace std;
void solveHelper(int **edges, int n, int s, bool *visited) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
        	if (!visited[i] && edges[v][i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int solve(int n,int m,vector<int>u,vector<int>v) {
    int **edges = new int*[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int s = u[i] - 1;
        int d = v[i] - 1;
        edges[s][d] = 1;
        edges[d][s] = 1;
	}
	bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            cnt++;
            solveHelper(edges, n, i, visited);
        }
    }
    for(int i = 0; i < n; i++)
        delete [] edges[i];
	delete [] edges;
    delete [] visited;
    return cnt;
}
int main() {
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++) {
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}