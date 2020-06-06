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

vector<int> *findPath(Node *root, int k) {
    if (root == NULL)
        return NULL;
    if (root -> data == k) {
        vector<int> *ans = new vector<int>;
        ans->push_back(root->data);
        return ans;
    }
    else if (root -> data > k) {
        vector<int> *ans = findPath(root->left, k);
        if (ans != NULL)
            ans->push_back(root->data);
        return ans;
    }
    else {
        vector<int> *ans = findPath(root->right, k);
        if (ans != NULL)
            ans->push_back(root->data);
        return ans;
    }
}

int main() {
    Node *root = takeInputLevelWise();
    int k; cin>>k;
    vector<int> *res = findPath(root, k);
    vector<int>::iterator i = res -> begin();
    while (i != res -> end()) {
        cout<<*i<<" ";
        i++;
    }
    cout<<endl;
    return 0;
}