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

int countNodes(Node *root) {
    if (root == NULL)
        return 0;
    queue<Node*> q;
    q.push(root);
    int count = 0;
    while (!q.empty()) {
        int n = q.size();
        count += n;
        while (n--) {
            Node *p = q.front();
            q.pop();
            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL)
                q.push(p->right);
        }
    }
    return count;
}

int main() {

    Node *root = takeInputLevelWise();
    cout<<countNodes(root)<<endl;
    return 0;
    
}