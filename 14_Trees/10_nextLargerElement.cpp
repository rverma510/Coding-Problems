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

void preOrder(Node *root, int n, int &ans) {
    if (root == NULL)
        return;
    if (root->val > n) {
        if (ans < n || ans > root->val)
            ans = root->val;
    }
    for (int i = 0; i < root->child.size(); i++) {
        preOrder(root->child[i], n, ans);
    }
}

int main() {
    // Node *root = newNode(4);
    // (root->child).push_back(newNode(2));
    // (root->child).push_back(newNode(3));
    // (root->child).push_back(newNode(5));
    // (root->child[1]->child).push_back(newNode(1));
    int n;
    cin>>n;
    Node *root = takeInputLevelWise();
    int ans = INT_MIN;
    preOrder(root, n, ans);
    cout<<ans<<endl;
    return 0;
}