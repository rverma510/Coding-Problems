/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> res;
    TreeNode *curr = A;
    stack<TreeNode*> st;
    while (curr != NULL || !st.empty()) {
        if (curr == NULL && !st.empty()) {
            curr = st.top();
            st.pop();
            curr = curr->right;
            continue;
        }
        res.push_back(curr->val);
        st.push(curr);
        curr = curr->left;
    }
    return res;
}
