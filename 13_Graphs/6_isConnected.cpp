#include<bits/stdc++.h>
using namespace std;
bool isConnected(int **edges, int n, int s, bool *visited) {
    int count = 1;
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
                count++;
            }
        }
    }
    return count == n;
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
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    if(isConnected(edges, n, 0,visited))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    return 0;
}