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
    cout<<"Enter node data : ";
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

void traversalLeft(Node *root) {
    if (root == NULL || (root -> left == NULL && root->right == NULL))
        return;
    cout<<root->val<<" ";
    if (root->left != NULL)
        traversalLeft(root->left);
    else
        traversalLeft(root->right);
}

void traversalLeaf(Node *root) {
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL) {
        cout<<root->val<<" ";
        return;
    }
    traversalLeaf(root->left);
    traversalLeaf(root->right);
}

void traversalRight(Node *root) {
    if(root == NULL || (root -> left == NULL && root->right == NULL))
        return;
    if(root->right != NULL) 
        traversalRight(root->right);
    else
        traversalRight(root->left);
    cout<<root->val<<" ";
}

int main() {
    Node *root = takeInputLevelWise();
    traversalLeft(root);
    traversalLeaf(root);
    traversalRight(root -> right);
    return 0;
    
}