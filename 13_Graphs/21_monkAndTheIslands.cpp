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
        graph.shortestPath(0);
    }
    return 0;
}