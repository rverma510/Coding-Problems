/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void helper(TreeNode *A, int k, map<int, vector<int>> &m) {
    if (A == NULL)
        return;
    m[k].push_back(A->val);
    helper(A->left, k + 1, m);
    helper(A->right, k, m);
}
vector<int> Solution::solve(TreeNode* A) {
    vector<int> res;
    if (A == NULL) 
        return res;
    map<int, vector<int>> m;
    helper(A, 0, m);
    for (auto i: m) {
        for (int j = 0; j < i.second.size(); j++) {
            res.push_back(i.second[j]);
        }
    }
    return res;
}
