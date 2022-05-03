// https://leetcode.com/problems/sum-root-to-leaf-numbers

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

void helper(TreeNode *root, int ans, int &res) {
    if (root == nullptr) return;
    ans = ans * 10 + root -> val;
    if (root -> left == nullptr & root -> right == nullptr) {
        res += ans;
    }
    helper(root -> left, ans, res);
    helper(root -> right, ans, res);
}
int sumNumbers(TreeNode* root) {
    int res = 0;
    helper(root, 0, res);   
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
    cout << sumNumbers(root) << '\n';
    return 0;
}