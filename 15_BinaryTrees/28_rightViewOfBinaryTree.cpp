/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    if (A == NULL)
        return {};
    vector<int> res;
    queue<TreeNode*> q;
    q.push(A);
    int tmp = A->val;
    while (!q.empty()) {
        int n = q.size();
        res.push_back(tmp);
        while (n--) {
            TreeNode *p = q.front();
            q.pop();
            if (p->left != NULL) {
                q.push(p->left);
                tmp = p->left->val;
            }
            if (p->right != NULL) {
                q.push(p->right);
                tmp = p->right->val;
            }
        }
    }
    return res;
}
