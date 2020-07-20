/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* root) {
    if (root == NULL)
        return NULL;
    root->left = solve(root->left);
    root->right = solve(root->right);
    if (root->left != NULL && root->right != NULL) {
        return root;
    }
    else if (root->left != NULL) {
        return root->left;
    }
    else if (root->right != NULL) {
        return root->right;
    }
    else {
        return root;
    }
}
