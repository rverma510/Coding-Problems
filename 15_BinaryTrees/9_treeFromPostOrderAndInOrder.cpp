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

int postIndex = -1;

Node *getTreeFromPostOrderAndInOrder(int *postOrder, int *inOrder, int s, int e) {
    if (s > e)
        return NULL;
    int val = postOrder[postIndex--];
    Node *root = newNode(val);
    if (s == e) 
        return root;
    int i;
    for (i = s; i <= e; i++)
        if (val == inOrder[i])
            break;
    root->right = getTreeFromPostOrderAndInOrder(postOrder, inOrder, i + 1, e);
    root->left = getTreeFromPostOrderAndInOrder(postOrder, inOrder, s, i - 1);
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
    int *postOrder = new int[n];
    int *inOrder = new int[n];
    for (int i = 0; i < n; i++) 
        cin>>postOrder[i];
    for (int i = 0; i < n; i++) 
        cin>>inOrder[i];
    postIndex = n - 1;
    Node *root = getTreeFromPostOrderAndInOrder(postOrder, inOrder, 0, n - 1);
    levelOrderTraversal(root);
    return 0;
}