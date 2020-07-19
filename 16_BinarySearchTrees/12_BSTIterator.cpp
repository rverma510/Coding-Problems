/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
stack<TreeNode*> st;
BSTIterator::BSTIterator(TreeNode *root) {
    while (!st.empty()) {
        st.pop();
    }
    TreeNode *node = root;
    while(node != NULL) {
        st.push(node);
        node = node->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !st.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    int v = st.top()->val;
    TreeNode *node = st.top()->right;
    st.pop();
    while(node != NULL) {
        st.push(node);
        node = node->left;
    }
    return v;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
