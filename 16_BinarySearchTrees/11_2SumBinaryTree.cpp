/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void helper(TreeNode* A, vector<int> &arr) {
    if (A == NULL)
        return;
    helper(A->left, arr);
    arr.push_back(A->val);
    helper(A->right, arr);
}
int Solution::t2Sum(TreeNode* A, int B) {
    vector<int> arr;
    helper(A, arr);
    int lo = 0, hi = arr.size() - 1;
    while (lo < hi) {
        if (arr[lo] + arr[hi] == B)
            return 1;
        else if (arr[lo] + arr[hi] > B)
            hi--;
        else
            lo++;
    }
    return 0;
}
