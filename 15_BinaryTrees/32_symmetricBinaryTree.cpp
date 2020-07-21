/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSymmetric(TreeNode* A) {
    if (A == NULL)
        return 1;
    queue<TreeNode*> q;
    q.push(A);
    while (!q.empty()) {
        vector<int> tmp;
        int n = q.size();
        while (n--) {
            TreeNode *p = q.front();
            q.pop();
            if (p->left) {
                q.push(p->left);
                tmp.push_back(p->left->val);
            }
            else {
                tmp.push_back(-1);
            }
            if (p->right) {
                q.push(p->right);
                tmp.push_back(p->right->val);
            }
            else {
                tmp.push_back(-1);
            }
        }
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i] != tmp[tmp.size() - i - 1]) {
                return 0;
            }
        }
    }
    return 1;
}


// int traverse(TreeNode* r1, TreeNode* r2){
// if(r1 == NULL and r2 == NULL)
// return 1;
// if(r1 == NULL or r2 == NULL)
// return 0;
// return (r1->val == r2->val) and traverse(r1->left, r2->right) and traverse(r1->right, r2->left);
// }
// int Solution::isSymmetric(TreeNode* A) {
// return traverse(A->left, A->right);
// }