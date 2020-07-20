/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {
    if (A == NULL || A->val == B) {
        return {};
    }
    queue<TreeNode*> q;
    q.push(A);
    int par = INT_MIN;
    unordered_map<int, int> m;
    vector<int> res;
    while (!q.empty()) {
        m.clear();
        res.clear();
        int n = q.size();
        while (n--) {
            TreeNode *node = q.front();
            q.pop();
            if (node->left != NULL) {
                q.push(node->left);
                m[node->left->val] = node->val;
                if (node->left->val == B)
                    par = node->val;
            }
            if (node->right != NULL) {
                q.push(node->right);
                m[node->right->val] = node->val;
                if (node->right->val == B)
                    par = node->val;
            }
        }
        if (par != INT_MIN) {
            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                if (m[node->val] == par)
                    continue;
                res.push_back(node->val);
            }
        }
    }
    return res;
}
