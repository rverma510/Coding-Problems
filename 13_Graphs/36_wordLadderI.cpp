int Solution::solve(string A, string B, vector<string> &C) {
    unordered_map<string, bool> vis;
    for (int i = 0; i < C.size(); i++) {
        vis[C[i]] = false;
    }
    queue<string> q;
    q.push(A);
    vis[A] = true;
    
    unordered_map<string, int> dist;
    dist[A] = 1;

    while (!q.empty()) {
        string str = q.front();
        q.pop();
        for (int i = 0; i < str.size(); i++) {
            string tmp = str;
            for(int j = 0; j < 26; j++) {
                tmp[i] = j + 'a';
                if (vis.find(tmp) != vis.end() && !vis[tmp]) {
                    q.push(tmp);
                    vis[tmp] = true;
                    dist[tmp] = dist[str] + 1;
                }
            }
        }
    }
    return dist[B];
}