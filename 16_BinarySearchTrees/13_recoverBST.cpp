/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void helper(TreeNode *A, vector<int> &arr) {
    if (A == NULL)
        return;
    helper(A->left, arr);
    arr.push_back(A->val);
    helper(A->right, arr);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> arr = {};
    helper(A, arr);
    int i, j;
    for(i = 0; i < arr.size() - 1; i++) {
        if (arr[i] < arr[i + 1])
            continue;
        break;
    }
    for (j = arr.size() - 1; j > 0; j--) {
        if (arr[j] > arr[j - 1])
            continue;
        break;
    }
    return {arr[j], arr[i]};
}
