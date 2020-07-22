/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void helper(TreeNode *A, int m, int n, vector<vector<int>> &ans, vector<int> curr) {
    if (A == NULL) return;
    curr.push_back(A->val);
    if (A->val == m || A->val == n) {
        if (A->val == m) {
            m = INT_MIN;
            ans.push_back(curr);
        }
            
        if (A->val == n) {
            n = INT_MIN;
            ans.push_back(curr);
        }
            
    } 
    helper(A->left, m, n, ans, curr);
    helper(A->right, m, n, ans, curr);
}
 
int Solution::lca(TreeNode* A, int B, int C) {
    vector<vector<int>> ans;
    helper(A, B, C, ans, {});
    int tmp = -1;
    if (ans.size() == 2) {
        int i = 0, j = 0;
        while (i < ans[0].size() && j < ans[1].size()) {
            if (ans[0][i] == ans[1][j])
                tmp = ans[0][i];
            i++;
            j++;
        }
    }
    return tmp;
}
