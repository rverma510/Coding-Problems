/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
    queue<UndirectedGraphNode*> q;
    q.push(node);
    m[node] = new UndirectedGraphNode(node->label);
    while (!q.empty()) {
        UndirectedGraphNode *tmp = q.front();
        q.pop();
        for (auto i: tmp->neighbors) {
            if (m.find(i) == m.end()) {
                m[i] = new UndirectedGraphNode(i->label);
                q.push(i);
            }
            m[tmp]->neighbors.push_back(m[i]);
        }
    }
    return m[node];
}
