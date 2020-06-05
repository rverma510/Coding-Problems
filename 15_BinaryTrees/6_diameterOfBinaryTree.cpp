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
    cout<<"Enter root data : ";
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

int diameter(Node *root, int *ans) {
    if (root == NULL)
        return 0;
    int ans1 = diameter(root->left, ans);
    int ans2 = diameter(root->right, ans);
    if (*ans < ans1 + ans2)
        *ans = ans1 + ans2;
    return 1 + max(ans1, ans2);
}

int main() {
    Node *root = takeInputLevelWise();
    int ans = 0;
    diameter(root, &ans);
    cout<<ans<<endl;
    return 0;
}
// 1 2 3 4 7 -1 -1 5 -1 -1 8 6 -1 -1 9 -1 -1 -1 10 -1 -1