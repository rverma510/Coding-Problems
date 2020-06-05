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
            for (int i = 0; i < p->child.size(); i++) {
                q.push(p->child[i]);
            }
        }
        cout<<endl;
    }
}

void replaceWithDepthValue(Node *root, int depth) {
    if (root == NULL)
        return;
    root->val = depth;
    for (int i = 0; i < root->child.size(); i++) {
        replaceWithDepthValue(root->child[i], depth + 1);
    }
}

int main() {
    Node *root = takeInputLevelWise();
    replaceWithDepthValue(root, 0);
    levelOrderTraversal(root);
    return 0;
}