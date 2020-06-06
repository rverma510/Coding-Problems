#include<bits/stdc++.h>
using namespace std;

struct List {
    int val;
    List *next;
};

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

List *newListNode(int val) {
    List *tmp = new List;
    tmp->val = val;
    tmp->next = NULL;
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

vector<List*> getLevelWiseLinkedList(Node *root) {
    if (root == NULL)
        return {};
    vector<List*> res;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        List *head = NULL, *tmp = NULL;
        int n = q.size();
        while (n--) {
            Node *p = q.front();
            q.pop();
            List *x = newListNode(p->val);
            if (head == NULL) {
                head = x;
                tmp = x;
            }
            else {
                tmp->next = x;
                tmp = x;
            }
            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL)
                q.push(p->right);
        }
        res.push_back(head);
    }
    return res;
}

int main() {
    Node *root = takeInputLevelWise();
    vector<List*> levelWiseList = getLevelWiseLinkedList(root); 
    for (int i = 0; i < levelWiseList.size(); i++) {
        List *tmp = levelWiseList[i];
        while (tmp != NULL) {
            cout<<tmp->val<<" ";
            tmp = tmp -> next;
        }
        cout<<endl;
    }
    return 0;
    
}