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

vector<int>* getLongestPath(Node *root) {
    if (root == NULL)
        return NULL;
    vector<int> *ans1 = getLongestPath(root->left);
    vector<int> *ans2 = getLongestPath(root->right);
    if (ans1 == NULL && ans2 == NULL) {
        vector<int> *ans = new vector<int>;
        ans->push_back(root->val);
        return ans;
    }
    if(ans1 == NULL) {
        ans2 -> push_back(root -> val);
        return ans2;
    }
    else if(ans2 == NULL) {
        ans1 -> push_back(root -> val);
        return ans1;
    }
    else {
        if (ans1 -> size() >= ans2 ->size()) {
            ans1 -> push_back(root -> val);
            return ans1;
        }
        else {
            ans2 -> push_back(root -> val);
            return ans2;
        }
    }   
}

int main() {

    Node *root = takeInputLevelWise();
    vector<int> *res = getLongestPath(root);
    vector<int>::iterator i = res -> begin();
    for (; i != res -> end(); i++) {
        cout<<*i<<endl;
    }
    return 0;
    
}