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

Node *search(Node *root, int n) {
    if (root == NULL)
        return NULL;
    if (root -> data == n)
        return root;
    else if(root -> data > n)
        return search(root -> left, n);
    else
        return search(root -> right, n);
}

int main() {
    Node *root = takeInputLevelWise();
    int n;
    cin>>n;
    Node *res = search(root, n);
    if(res != NULL)
        cout<<n;
    cout<<endl;
    return 0;
}