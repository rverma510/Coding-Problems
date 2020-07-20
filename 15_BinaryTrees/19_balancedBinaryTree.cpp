/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int helper(TreeNode *A, int &ans) {
    if (A == NULL) {
        return 0;
    }
    int l = helper(A->left, ans);
    int r = helper(A->right, ans);
    if (abs(l - r) > 1)
        ans = 0;
    return 1 + max(l, r);
    
}
int Solution::isBalanced(TreeNode* A) {
    int ans = 1;
    helper(A, ans);
    return ans;
}
