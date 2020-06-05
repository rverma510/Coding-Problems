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

Node *takeInput() {
    int val, childCount;
    cout<<"Enter next node data : ";
    cin>>val;
    Node *root = newNode(val);
    cout<<"Enter child count for "<<val<<" : ";
    cin>>childCount;
    for (int i = 0; i < childCount; i++) {
        Node *child = takeInput();
        root->child.push_back(child);
    }
    return root;
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
            cout<<"Enter node val : ";
            cin>>val; 
            Node *child = newNode(val);
            p->child.push_back(child);
            q.push(child);
        }
    }
    return root;
}

void print(Node *root) {
    string s = to_string(root->val) + " : ";
    for (int i = 0; i < root->child.size(); i++) {
        s = s + to_string(root->child[i]->val) + ", ";
    }
    cout<<s<<endl;
    for (int i = 0; i < root->child.size(); i++) {
        print(root->child[i]);
    }
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

int main() {
    // Node *root = newNode(4);
    // (root->child).push_back(newNode(2));
    // (root->child).push_back(newNode(3));
    // (root->child).push_back(newNode(5));
    // (root->child[1]->child).push_back(newNode(1));
    Node *root = takeInputLevelWise();
    levelOrderTraversal(root);    
    return 0;
}