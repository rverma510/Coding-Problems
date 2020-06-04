#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
class Graph {
    int V;
    vector<int> *adj;
    public:
        Graph(int V) {
            this->V = V;
            adj = new vector<int>[V];
        }
        ~Graph() {
            delete [] adj;
        }
        void addEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        void dfs(int s, vector<int> *component, bool *visited);
        vector<vector<int>*>* getResult();
};
void Graph::dfs(int s, vector<int> *component, bool *visited) {
    visited[s] = true;
    component -> push_back(s);
    for (auto i: adj[s]) {
        if (!visited[i])
            dfs(i, component, visited);
    }
}
vector<vector<int>*>* Graph::getResult() {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    vector<vector<int>*>* output = new vector<vector<int>*>();
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int>* component = new vector<int>();
            dfs(i, component, visited);
            output -> push_back(component);
        }
    }
    delete [] visited;
    return output;
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
            graph.addEdge(x - 1, y - 1);
        }
        int *bananas = new int[n];
        for (int i = 0; i < n; i++) {
            cin>>bananas[i];
        } 
        ll ans = 0;
        vector<vector<int>*>* output = graph.getResult();
        vector<vector<int>*>::iterator it1 = output -> begin();
        while (it1 != output -> end()) {
            vector<int> *component = *it1;
            vector<int>::iterator it2 = component -> begin();
            ll tmp = 0;
            while (it2 != component -> end()) {
                tmp += bananas[*it2];
                it2++;
            }
            ans = max(ans, tmp);
            delete component;
            it1++;
        }
        cout<<ans<<endl;
        delete output;
    }

    return 0;
}