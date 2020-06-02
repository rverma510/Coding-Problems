#include<iostream>
#include<vector>
using namespace std;
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
    int count = 0;
    int src = 0;
    for (int src = 0; src < n; src++) {   
        for (int i = 0; i < n; i++) {
            if (edges[src][i]) {
                for (int j = 0; j < n; j++) {
                    if (edges[i][j] && edges[j][src])
                        count++;
                }
            }
        }
    }
    return count / 6;
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