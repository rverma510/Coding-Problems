/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> res;
    TreeNode *curr = A;
    stack<TreeNode*> st;
    while (curr != NULL || !st.empty()) {
        if (curr == NULL && !st.empty()) {
            curr = st.top();
            curr = curr->right;
            if (curr == NULL) {
                while (!st.empty() && st.top()->right == curr) {
                    res.push_back(st.top()->val);
                    curr = st.top();
                    st.pop();
                }
                curr = NULL;
            }
            continue;
        }
        st.push(curr);
        curr = curr->left;
    }
    return res;
}
