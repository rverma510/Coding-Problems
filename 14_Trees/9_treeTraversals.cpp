#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    vector<Node*> child;
};

Node *newNode(int val) {
    Node *temp = new Node;
    temp->val = val;
    return temp;
}

Node *takeInputLevelWise() {
    int val, childCount;
    cout<<"Enter node val : ";
    cin>>val;
    Node *root = newNode(val);
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *p = q.front();
        q.pop();
        cout<<"Enter child count for "<<p->val<<" : ";
        cin>>childCount;
        for (int i = 0; i < childCount; i++) {
            cout<<"Enter "<<i+1<<"th child of "<<p->val<<" : ";
            cin>>val; 
            Node *child = newNode(val);
            p->child.push_back(child);
            q.push(child);
        }
    }
    return root;
}

void preOrder(Node *root) {
    if (root == NULL)
        return;
    cout<<root->val<<" ";
    for (int i = 0; i < root->child.size(); i++) {
        preOrder(root->child[i]);
    }
}

void postOrder(Node *root) {
    if (root == NULL)
        return;
    for (int i = 0; i < root->child.size(); i++) {
        postOrder(root->child[i]);
    }
    cout<<root->val<<" ";
}

int main() {
    // Node *root = newNode(4);
    // (root->child).push_back(newNode(2));
    // (root->child).push_back(newNode(3));
    // (root->child).push_back(newNode(5));
    // (root->child[1]->child).push_back(newNode(1));
    Node *root = takeInputLevelWise();
    preOrder(root);
    cout<<endl;
    return 0;
}