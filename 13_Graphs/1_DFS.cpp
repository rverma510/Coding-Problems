#include<bits/stdc++.h>
using namespace std;

void print(int **edges, int n, int s, bool *visited) {
    cout<<s<<endl;
    visited[s] = true;
    for (int i = 0; i < n; i++) {
        if (edges[s][i] && !visited[i]) {
            print(edges, n, i, visited);
        }
    }
}

int main() {
    int n;
    int e;
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
    print(edges, n, 0, visited);
    for(int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
    delete [] visited;
    return 0;
}