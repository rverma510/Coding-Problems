#include<bits/stdc++.h>
using namespace std;

void print(int **edges, int n, bool *visited) {
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        queue<int> q;
        q.push(i);
        visited[i] = true;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            cout<<v<<" ";
            for (int j = 0; j < n; j++) {
                if (!visited[j] && edges[v][j]) {
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
    }
    cout<<endl;
}

int main() {
    int n, e;
    cin>>n>>e;
    int **edges = new int*[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++) {
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    print (edges, n, visited);
    return 0;
}