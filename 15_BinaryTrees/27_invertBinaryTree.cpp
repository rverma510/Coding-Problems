/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* A) {
    if(A == NULL)
        return NULL;
    queue<TreeNode*> q;
    q.push(A);
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        TreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
    return A;
}
