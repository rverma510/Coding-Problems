/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* buildUtil(vector<int> &in, vector<int> &post, int inStrt, 
                int inEnd, int &pIndex) {
    if (inStrt > inEnd) 
        return NULL; 
    TreeNode* node = new TreeNode(post[pIndex]); 
    pIndex--; 
    if (inStrt == inEnd) 
        return node; 
    int i; 
    for (i = inStrt; i <= inEnd; i++) { 
        if (in[i] == node->val) 
            break; 
    } 
    node->right = buildUtil(in, post, i + 1, inEnd, pIndex); 
    node->left = buildUtil(in, post, inStrt, i - 1, pIndex); 
  
    return node; 
} 

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = B.size() - 1;
    return buildUtil(A, B, 0, A.size() - 1, n);
}
