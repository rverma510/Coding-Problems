#include<bits/stdc++.h>
using namespace std;
void printConnectedComponentHelper(int **edges, int n, int s, bool *visited) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    vector<int> ans;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        ans.push_back(v);
        for (int i = 0; i < n; i++) {
            if (!visited[i] && edges[v][i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto a: ans) {
        cout<<a<<" ";
    }
    cout<<endl;
}
void printConnectedComponent(int **edges, int n) {
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            printConnectedComponentHelper(edges, n, i, visited);
    }
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
    printConnectedComponent(edges, n);
    return 0;
}