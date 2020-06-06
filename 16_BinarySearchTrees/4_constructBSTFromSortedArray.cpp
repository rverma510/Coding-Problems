#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data) {
    Node *tmp = new Node;
    tmp -> data = data;
    tmp -> left = NULL;
    tmp -> right = NULL;
    return tmp;
}

void preOrder(Node *root) {
    if (root == NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

Node *constructBST(int *input, int l, int r) {
    if (l > r)
        return NULL;
    int mid = l + (r - l) / 2;
    Node *root = newNode(input[mid]);
    root->left = constructBST(input, l, mid - 1);
    root->right = constructBST(input, mid + 1, r);
    return root;
} 

int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    Node *root = constructBST(arr, 0, n - 1);
    preOrder(root);
    cout<<endl;
    return 0;
}