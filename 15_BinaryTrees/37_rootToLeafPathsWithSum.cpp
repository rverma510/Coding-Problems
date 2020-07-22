/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void helper(TreeNode *A, int B, vector<vector<int>> &ans, vector<int> curr) {
    if (A == NULL)
        return;
    else if (A->left == NULL && A->right == NULL && B == A->val) {
        curr.push_back(A->val);
        ans.push_back(curr);
        return;
    }
    curr.push_back(A->val);
    helper(A->left, B - A->val, ans, curr);
    helper(A->right, B - A->val, ans, curr);
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> ans;
    helper(A, B, ans, {});
    return ans;
}
