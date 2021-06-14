#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> m;
        for (int i = 0; i < words.size(); i++) {
            string tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            m[tmp] = i;
        }
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j <= words[i].size(); j++) {
                string pre = words[i].substr(0, j);
                string suf = words[i].substr(j);
                
                if (m.count(pre) && isPalindrome(suf) && m[pre] != i) {
                    ans.push_back({i, m[pre]});
                }
                if (!pre.empty() && m.count(suf) && isPalindrome(pre) && m[suf] != i) {
                    ans.push_back({m[suf], i});
                }
            }
        }
        
        return ans;
    }    
    
    bool isPalindrome(string str){
        
        string tmp = str;
        reverse(tmp.begin(), tmp.end());
        return (str == tmp) ;
    }
};

int main() {
    vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
    Solution sol;
    vector<vector<int>> ans = sol.palindromePairs(words);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << ' ' << ans[i][1] << '\n';
    }
    return 0;
}