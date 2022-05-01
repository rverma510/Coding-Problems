#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void helper(TreeNode *root, int targetSum, vector<int> &r, vector<vector<int>> &res) {
    if (!root) return;
    r.push_back(root -> val);
    if (!(root -> left) && !(root -> right) && targetSum == root -> val) {
        res.push_back(r);
    }
    helper(root -> left, targetSum - root -> val, r, res);
    helper(root -> right, targetSum - root -> val, r, res);
    r.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> res;
    vector<int> r;
    helper(root, targetSum, r, res);
    return res;
}

TreeNode* input() {
    int val;
    cin >> val;
    if (val == -1) return nullptr;
    TreeNode *root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            TreeNode *node = q.front(); q.pop();
            cin >> val;
            if (val != -1) {
                node -> left = new TreeNode(val);
                q.push(node -> left);
            }
            cin >> val;
            if (val != -1) {
                node -> right = new TreeNode(val);
                q.push(node -> right);
            }        
        }
    }
    return root;
}

int main() {
    TreeNode *root = input();
    int targetSum; cin >>targetSum;
    vector<vector<int>> res = pathSum(root, targetSum);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

/*

5 4 8 11 -1 13 4 7 2 -1 -1 5 1 -1 -1 -1 -1 -1 -1 -1 -1
22

*/