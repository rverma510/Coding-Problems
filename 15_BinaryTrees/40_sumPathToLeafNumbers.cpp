/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define mod 1003
typedef long long int ll;
void helper(TreeNode *A, ll &sum, ll curr) {
    if (A == NULL) return;
    curr = (curr * 10 + A->val) % mod;
    if (A->left == NULL && A->right == NULL) {
        sum += curr;
    }
    helper(A->left, sum, curr);
    helper(A->right, sum ,curr);
}

int Solution::sumNumbers(TreeNode* A) {
    ll sum = 0;
    helper(A, sum, 0);
    return sum % mod;
}
