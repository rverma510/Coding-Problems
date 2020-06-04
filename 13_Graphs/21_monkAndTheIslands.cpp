#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;

class Graph {
    int V;
    list<iPair> *adj;
    public:
        Graph(int v);
        void addEdge(int u, int v, int w);
        void shortestPath(int s);
        int bfs(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}


void Graph::shortestPath(int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INT_MAX);
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        list<iPair>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++) {
            int v = (*i).first;
            int w = (*i).second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout<<dist[V - 1]<<endl;
}

int Graph::bfs(int src) {
    vector<int> level(V, 0);
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto i: adj[u]) {
            int v = i.first;
            if (!visited[v]) {
                q.push(v);
                visited[v] = true; 
                level[v] = level[u] + 1;
            }
        }
    }
    return level[V - 1];
}

 
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n, m, x, y;
        cin>>n;
        Graph graph(n);
        cin>>m;
        for (int i = 0; i < m; i++) {
            cin>>x>>y;
            graph.addEdge(x - 1, y - 1, 1);
        }
        cout<<graph.bfs(0)<<endl;
    }
    return 0;
}