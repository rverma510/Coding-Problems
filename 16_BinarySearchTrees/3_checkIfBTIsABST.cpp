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

Node *takeInputLevelWise() {
    int n;
    cout<<"Enter root node data : ";
    cin>>n;
    if (n == -1)
        return NULL;
    Node *root = newNode(n);
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *p = q.front();
        q.pop();
        cout<<"Enter left child of "<<p -> data<<" : ";
        cin>>n;
        if (n != -1) {
            p -> left = newNode(n);
            q.push(p -> left);
        }
        cout<<"Enter right child of "<<p -> data<<" : ";
        cin>>n;
        if (n != -1) {
            p -> right = newNode(n);
            q.push(p -> right);
        }
    }
    return root;
}

int minimumBT(Node *root) {
    if (root == NULL)
        return INT_MAX;	
    return min(root->data, min(minimumBT(root->left), minimumBT(root->right)));
}

int maximumBT(Node *root) {
    if (root == NULL)
        return INT_MIN;	
    return max(root->data, max(maximumBT(root->left), maximumBT(root->right)));
}

bool isBST(Node *root){
    if (root == NULL)
        return true;
	int leftmax = maximumBT(root->left);
	int rightmax = minimumBT(root->right);
    if (root->data < leftmax || root->data > rightmax)
	    return false;
	bool ans1 = isBST(root->left);
    bool ans2 = isBST(root->right);
    return ans1 & ans2;

}

int main() {
    Node *root = takeInputLevelWise();
    bool ans = isBST(root);
    if (ans)
        cout<<"true\n";
    else
        cout<<"false\n";
    return 0;
}