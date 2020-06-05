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

Node *levelOrderTraversal(Node *root) {
    if (root == NULL)
        return NULL;
    Node *ans = NULL;
    int sum = INT_MIN;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *p = q.front();
        q.pop();
        int tmp = p->val;
        for (int i = 0; i < p->child.size(); i++) {
            tmp += p->child[i]->val;
            q.push(p->child[i]);
        }
        if (tmp > sum) {
            sum = tmp;
            ans = p;
        }
    }
    return ans;
}


int main() {
    Node *root = takeInputLevelWise();
    Node *ans = levelOrderTraversal(root);
    if (ans != NULL)
        cout<<ans->val<<endl;
    else
        cout<<-1<<endl;
    return 0;
}