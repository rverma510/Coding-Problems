/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

  
void Solution::connect(TreeLinkNode* A) {
    if (A == NULL)
        return;
    queue<TreeLinkNode*> q;
    q.push(A);
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            TreeLinkNode *p = q.front();
            q.pop();
            if (n > 0)
                p->next = q.front();
            else
                p->next = NULL;
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
    }
}
