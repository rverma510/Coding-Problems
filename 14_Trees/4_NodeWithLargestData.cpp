#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    vector<Node *> child;
};

Node* newNode(int val) {
    Node *tmp = new Node;
    tmp -> val = val;
    return tmp;
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

int maxNode(Node *root) {
    if (root == NULL)
        return INT_MIN;
    int  mx = root->val;
    for (int i = 0; i < root->child.size(); i++) {
        mx = max(mx, maxNode(root->child[i]));
    }
    return mx;
}

int main() {
    Node *root = takeInputLevelWise();
    cout<<maxNode(root)<<endl;
}