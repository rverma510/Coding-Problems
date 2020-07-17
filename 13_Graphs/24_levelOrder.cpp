/*

Given a binary tree, return the level order traversal of its nodes’ values. 
(ie, from left to right, level by level).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


 #include<bits/stdc++.h>
 using namespace std;
vector<vector<int> > levelOrder(TreeNode* A) {
    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(A);
    while (!q.empty()) {
        int n = q.size();
        vector<int> tmp;
        while (n--) {
            TreeNode *p = q.front();
            q.pop();
            tmp.push_back(p->val);
            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL) 
                q.push(p->right);
        }
        res.push_back(tmp);
    }
    return res;
}
