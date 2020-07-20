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
    unordered_map<int, int> m;
    m[A->val] = -1;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()) {
        TreeNode *p = q.front();
        q.pop();
        if (p->left != NULL) {
            q.push(p->left);
            m[p->left->val] = p->val;
        }
        if (p->right != NULL) {
            q.push(p->right);
            m[p->right->val] = p->val;
        }
    }
    vector<int> res;
    while (B != -1) {
        res.push_back(B);
        B = m[B];
    }
    reverse(res.begin(), res.end());
    return res;
}
