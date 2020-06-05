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

int countNode(Node *root) {
    if (root == NULL)
        return 0;
    int count = 1;
    for (int i = 0; i < root->child.size(); i++) {
        count += countNode(root->child[i]);
    }
    return count;
}

int main() {
    Node *root = takeInputLevelWise();
    cout<<countNode(root)<<endl;
}