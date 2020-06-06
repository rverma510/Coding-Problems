#include<bits/stdc++.h>
using namespace std;

struct List {
    int data;
    List *next;
};

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

List *BSTToLinkedlist(Node *root) {
    if (root == NULL)
        return NULL;
	List *list1 = BSTToLinkedlist(root->left);
    List *list2 = BSTToLinkedlist(root->right);
	List *tmp = list1;
    if (list1 == NULL) {
        list1 = new List;
        list1->data = root->data;
        list1->next = list2;
	}
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new List;
        tmp->next->data = root->data;
        tmp = tmp->next;
        tmp->next = list2;
    }    
    return list1;
    
}

int main() {
    Node *root = takeInputLevelWise();
    List *res = BSTToLinkedlist(root);
    List *tmp = res;
    while (tmp != NULL) {
        cout<<tmp->data<<" ";
        tmp = tmp -> next;
    }
    cout<<endl;
    return 0;
}