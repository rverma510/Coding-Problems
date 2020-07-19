/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* helper(const vector<int> &A, int lo, int hi) {
    if (lo > hi)
        return NULL;
    int mid = lo + (hi - lo) / 2;
    TreeNode *root = new TreeNode(A[mid]);
    root->left = helper(A, lo, mid - 1);
    root->right = helper(A, mid + 1, hi);
    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return helper(A, 0, A.size()-1);
}
