/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void helper(TreeNode *A, int &k, int &ans) {
    if (A == NULL)
        return;
    helper(A->left, k, ans);
    if ((ans == INT_MIN || ans != A->val) && k > 0) {
        ans = A->val;
        k--;
    }
    helper(A->right, k, ans);
}
 
int Solution::kthsmallest(TreeNode* A, int B) {
    int ans = INT_MIN;
    helper(A, B, ans);
    return ans;
}
