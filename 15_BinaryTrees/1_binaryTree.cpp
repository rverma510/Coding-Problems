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

Node *takeInput() {
    int val;
    cout<<"Enter node data : ";
    cin>>val;
    if (val == -1) {
        return NULL;
    }
    Node *root = newNode(val);
    root->left = takeInput();
    root->right = takeInput();
    return root;
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

void print(Node *root) {
    if (root == NULL)
        return;
    cout<<root->val<<" : ";
    if (root->left != NULL)
        cout<<"L - "<<root->left->val;
    if (root->right != NULL)
        cout<<", R - "<<root->right->val;
    cout<<endl;
    print(root->left);
    print(root->right);
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

    Node *root = takeInputLevelWise();
    levelOrderTraversal(root);
    return 0;
    
}