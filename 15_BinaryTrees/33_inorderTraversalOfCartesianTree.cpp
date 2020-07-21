/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode *insert(TreeNode *root, int val) {
    if (root == NULL) {
        root = new TreeNode(val);
        return root;
    }
    if (val > root->val) {
        TreeNode *node = new TreeNode(val);
        node->left = root;
        return node;
    }
    else {
        root->right = insert(root->right, val);
        return root;
    }
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    if (A.size() == 0) {
        return NULL;
    }
    TreeNode *root = new TreeNode(A[0]);
    for (int i = 1; i < A.size(); i++) {
        root =insert(root, A[i]);
    }
    return root;
}
