#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data) {
    Node *tmp = new Node;
    tmp -> data = data;
    tmp -> left = NULL;
    tmp -> right = NULL;
    return tmp;
}

Node *takeInputLevelWise() {
    int n;
    cout<<"Enter root node data : ";
    cin>>n;
    if (n == -1)
        return NULL;
    Node *root = newNode(n);
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *p = q.front();
        q.pop();
        cout<<"Enter left child of "<<p -> data<<" : ";
        cin>>n;
        if (n != -1) {
            p -> left = newNode(n);
            q.push(p -> left);
        }
        cout<<"Enter right child of "<<p -> data<<" : ";
        cin>>n;
        if (n != -1) {
            p -> right = newNode(n);
            q.push(p -> right);
        }
    }
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
            cout<<p->data<<" ";
            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL)
                q.push(p->right);
        }
        cout<<endl;
    }
}

void insertDuplicateNode(Node *root) {
    if (root == NULL)
        return;
    Node *tmp = newNode(root->data);
    tmp->left = root->left;
    root->left = tmp;
    insertDuplicateNode(tmp->left);
    insertDuplicateNode(root->right);
}

int main() {
    Node *root = takeInputLevelWise();
    insertDuplicateNode(root);
    levelOrderTraversal(root);
    return 0;
}