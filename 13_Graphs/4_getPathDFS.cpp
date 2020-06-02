#include<bits/stdc++.h>
using namespace std;
vector<int> getPath(int **edges, int n, int s, int d, bool *visited) {
    if (s == d) {
        return {s};
    }
    visited[s] = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && edges[s][i]) {
            vector<int> ans = getPath(edges, n, i, d, visited);
            if(ans.size()) { 
                ans.push_back(s);
                return ans;
            }
        }
    }
    return {};
}
int main() {
    int n, e, s, d;
    cin>>n>>e;
    int **edges = new int*[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++) {
        cin>>s>>d;
        edges[s][d] = 1;
        edges[d][s] = 1;
    }
    cin>>s>>d;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    vector<int> res = getPath(edges, n, s, d, visited);
    if (res.size()) {
        for (int i = 0; i < res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    for(int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
    delete [] visited;
    return 0;
}
