#include<bits/stdc++.h>
using namespace std;

bool hasPath(int **edges, int n, int s, int d, bool *visited) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == d) {
            return true;
        }
        for (int i = 0; i < n; i++) {
            if (edges[v][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return false;
}

int main() {
    int n, e, s, d;;
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
    cin>>s>>d;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    if(hasPath(edges, n, s, d, visited))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    for(int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
    delete [] visited;
    return 0;
}