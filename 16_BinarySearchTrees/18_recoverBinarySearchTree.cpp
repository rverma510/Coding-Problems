// 

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *pre = nullptr, *firstMis = nullptr, *secMis = nullptr;

void helper1(TreeNode* root, vector<TreeNode*> &l) {
    if (!root) return;
    helper1(root -> left, l);
    l.push_back(root);
    helper1(root -> right, l);
}

void helper2(TreeNode *root) {
    if (root == nullptr) return;
    helper2(root -> left);
    if (pre -> val > root -> val) {
        if (firstMis == nullptr) {
            firstMis = pre;
        }
        secMis = root;
    }
    pre = root;
    helper2(root -> right);
}

void recoverTree(TreeNode* root) {
    // vector<TreeNode*> l;
    // helper1(root, l);
    // int n = l.size();
    // int i = n - 1, j = 0;
    // for (; i > 0; i--) {
    //     if (l[i - 1] -> val >= l[i] -> val) {
    //         break;
    //     }
    // }
    // for (; j < i; j++) {
    //     if (l[j] -> val >= l[j + 1] -> val) {
    //         break;
    //     }
    // }
    // int tmp = l[j] -> val;
    // l[j] -> val = l[i] -> val;
    // l[i] -> val = tmp;
    pre = root;
    while (pre -> left) pre = pre -> left;
    firstMis = secMis = nullptr;
    helper2(root);
    int tmp = firstMis -> val;
    firstMis -> val = secMis -> val;
    secMis -> val = tmp;
}

TreeNode* input() {
    int val;
    cin >> val;
    if (val == -1) return nullptr;
    TreeNode *root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            TreeNode *node = q.front(); q.pop();
            cin >> val;
            if (val != -1) node -> left = new TreeNode(val);
            cin >> val;
            if (val != -1) node -> right = new TreeNode(val);        
        }
    }
    return root;
}

void print(TreeNode *root) {
    if (!root) return;
    cout << root -> val << ' ';
    print(root -> left);
    print(root -> right);
}

int main() {
    TreeNode *root = input();
    recoverTree(root);
    print(root);
    cout << '\n';
    return 0;
}