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

void elementsInRangeK1K2(Node *root, int k1, int k2) {
    if (root == NULL)
        return;
	if (k2 < root -> data) {
        elementsInRangeK1K2(root -> left, k1, k2);
    }
    else if (k1 > root -> data) {
        elementsInRangeK1K2(root -> right, k1, k2);
    }
    else {
        elementsInRangeK1K2(root -> left, k1, k2);
        cout<<root -> data<<" ";
        elementsInRangeK1K2(root -> right, k1, k2); 
    }

}

int main() {
    Node *root = takeInputLevelWise();
    int k1, k2;
    cin>>k1>>k2;
    elementsInRangeK1K2(root, k1, k2);
    cout<<endl;
    return 0;
}