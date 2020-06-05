#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {    
    int t;
    cin>>t;
    while (t--) {
        ll n;
        cin>>n;
        unordered_map<int, vector<int>> mp;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin>>tmp;
            mp[tmp].push_back(i);
        }
        ll handshake = 0;
        queue<int> q;
        q.push(mp[0][0]);
        ll depth = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int p = q.front();
                q.pop();
                handshake += depth;
                for (int i = 0; i < mp[p].size(); i++)
                    q.push(mp[p][i]);
                mp.erase(p);
            }
            depth++;
        }
        cout<<handshake<<" "<< ((n * (n - 1)) / 2) - handshake<<endl;
    }    
    return 0;
}