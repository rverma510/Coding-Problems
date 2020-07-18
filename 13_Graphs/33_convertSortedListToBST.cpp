/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
TreeNode* helper(vector<int> &v, int lo, int hi) {
    if (lo > hi) {
        return NULL;
    }
    int mid = lo + (hi - lo) / 2;
    TreeNode *root = new TreeNode(v[mid]);
    root->left = helper(v, lo, mid - 1);
    root->right = helper(v, mid + 1, hi);
    return root;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> v;
    while (A != NULL) {
        v.push_back(A->val);
        A = A->next;
    }
    TreeNode *root = helper(v, 0, v.size() - 1);
    return root;
}
