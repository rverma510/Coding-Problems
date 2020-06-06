#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
};

Node *newNode(int val) {
    Node *tmp = new Node;
    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

int preIndex = 0;

Node *getTreeFromPreOrderAndInOrder(int *preOrder, int *inOrder, int s, int e) {
    if (s > e)
        return NULL;
    int val = preOrder[preIndex++];
    Node *root = newNode(val);
    if (s == e) 
        return root;
    int i;
    for (i = s; i <= e; i++)
        if (val == inOrder[i])
            break;
    root->left = getTreeFromPreOrderAndInOrder(preOrder, inOrder, s, i - 1);
    root->right = getTreeFromPreOrderAndInOrder(preOrder, inOrder, i + 1, e);
    return root;
}

void levelOrderTraversal(Node *root) {
    if (root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            Node *p = q.front();
            q.pop();
            cout<<p->val<<" ";
            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL)
                q.push(p->right);
        }
        cout<<endl;
    }
}


int main() {
    int n;
    cin>>n;
    int *preOrder = new int[n];
    int *inOrder = new int[n];
    for (int i = 0; i < n; i++) 
        cin>>preOrder[i];
    for (int i = 0; i < n; i++) 
        cin>>inOrder[i];
    preIndex = 0;
    Node *root = getTreeFromPreOrderAndInOrder(preOrder, inOrder, 0, n - 1);
    levelOrderTraversal(root);
    return 0;
}