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

void levelOrderTraversal(Node *root) {
    if (root == NULL)
        return;
    queue<Node*> q;
    cout<<root->val<<" ";
    if (root->left != NULL)
        q.push(root->left);
    if (root->right != NULL)
        q.push(root->right);
    while (!q.empty()) {
        int n = q.size();
        vector<Node*> res;
        while (n--) {
            Node *p = q.front();
            q.pop();
            res.push_back(p);
            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL)
                q.push(p->right);
        }
        n = res.size();
        for (int i = 0; i < n / 2; i++) {
            cout<<res[i] -> val<<" "<<res[n - i - 1] -> val<<" ";
        }
    }
    cout<<endl;
}

int main() {

    Node *root = takeInputLevelWise();
    levelOrderTraversal(root);
    return 0;
    
}