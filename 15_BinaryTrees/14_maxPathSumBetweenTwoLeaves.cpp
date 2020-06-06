#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

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

ll maxPathSumBetweenTwoLeaves(Node *root, ll &ans) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->val;
    ll ans1 = maxPathSumBetweenTwoLeaves(root->left, ans);
    ll ans2 = maxPathSumBetweenTwoLeaves(root->right, ans);
    if (root->left != NULL && root->right != NULL) {
        ans = max(ans, ans1 + ans2 + root->val);
    }
    return root->val + max(ans1, ans2);
}

int main() {
    Node *root = takeInputLevelWise();
    ll ans = 0;
    maxPathSumBetweenTwoLeaves(root, ans);
    cout<<ans<<endl;
    return 0;
    
}