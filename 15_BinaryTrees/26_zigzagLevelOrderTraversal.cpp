/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> res;
    if (A == NULL) {
        return res;
    }
    vector<TreeNode*> q;
    q.push_back(A);
    int flip = 1;
    while (q.size() > 0) {
        vector<int> tmp;
        if (flip) {
            for (int i = 0; i < q.size(); i++) {
                tmp.push_back(q[i]->val);
            }
            res.push_back(tmp);
            flip ^= 1;
        }
        else {
            for (int i = q.size() - 1; i >= 0; i--) {
                tmp.push_back(q[i]->val);
            }
            res.push_back(tmp);
            flip ^= 1;
        }
        int n = q.size(); 
        while (n--) {
            TreeNode *node = q[0];
            q.erase(q.begin());
            if (node->left != NULL) 
                q.push_back(node->left);
            if (node->right != NULL)
                q.push_back(node->right);
        }
    }
    return res;
}
