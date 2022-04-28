// https://leetcode.com/problems/validate-binary-search-tree

#include <bits/stdc++.h>
using namespace std;

bool helper(TreeNode *root, TreeNode *min, TreeNode *max) {
    if (!root) return true;
    if (min && min -> val >= root -> val || max && max -> val <= root -> val) return false;
    return helper(root -> left, min, root) && helper(root -> right, root, max);
}
bool isValidBST(TreeNode* root) {
    return helper(root, NULL, NULL);   
}

int main() {
    TreeNode *root = new TreeNode(2);
    root -> left = new TreeNode(1);
    root -> right = new TreeNode(3);

    TreeNode *root2 = new TreeNode(2);
    root -> left = new TreeNode(10);
    root -> right = new TreeNode(1);

    cout << isValidBST(root) << '\n';
    cout << isValidBST(root2) << '\n';

    return 0;
}