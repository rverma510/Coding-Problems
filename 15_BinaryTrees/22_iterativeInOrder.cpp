/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode *curr = A;
    while (curr != NULL || !st.empty()) {
        if (curr == NULL && !st.empty()) {
            curr = st.top();
            st.pop();
            res.push_back(curr->val);
            curr = curr->right;
            continue;
        }
        st.push(curr);
        curr = curr->left;
    }
    return res;
}