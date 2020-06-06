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

Node *takeInputLevelWise() {
    int n;
    cout<<"Enter root data : ";
    cin>>n;
    if (n == -1)
        return NULL;
    Node *root = newNode(n);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *p = q.front();
        q.pop();
        cout<<"Enter left child of "<<p->val<<" : ";
        cin>>n;
        if (n != -1) {
            p->left = newNode(n);
            q.push(p->left);
        }
        cout<<"Enter right child of "<<p->val<<" : ";
        cin>>n;
        if (n != -1) {
            p->right = newNode(n);
            q.push(p->right);
        } 
    }
    return root;
}

void preOrder(Node *root) {
    if (root == NULL)
        return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

void postOrder(Node *root) {
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}


int main() {
    Node *root = takeInputLevelWise();
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    return 0;
}
// 1 2 3 4 7 -1 -1 5 -1 -1 8 6 -1 -1 9 -1 -1 -1 10 -1 -1