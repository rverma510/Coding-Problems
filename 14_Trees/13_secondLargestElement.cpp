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

void preOrder(Node *root, Node *&largest, Node *&secLargest) {
    if (root == NULL)
        return;
    if (largest == NULL || root->val > largest->val) {
        secLargest = largest;
        largest = root;
    }
    for (int i = 0; i < root->child.size(); i++) {
        preOrder(root->child[i], largest, secLargest);
    }
}

int main() {
    Node *root = takeInputLevelWise();
    Node *largest = NULL;
    Node *secLargest = NULL;
    preOrder(root, largest, secLargest);
    if (secLargest != NULL)
        cout<<secLargest->val<<endl;
    return 0;
}