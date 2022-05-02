// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    if (!root) return root;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        Node *curr, *prev;
        curr = prev = nullptr;
        while (n--) {
            curr = q.front(); q.pop();
            if (curr -> left) q.push(curr -> left);
            if (curr -> right) q.push(curr -> right);
            if (prev) {
                prev -> next = curr;
            }
            prev = curr;
        }
    }
    return root;
}

Node* input() {
    int val;
    cin >> val;
    if (val == -1) return nullptr;
    Node *root = new Node(val);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            Node *node = q.front(); q.pop();
            cin >> val;
            if (val != -1) {
                node -> left = new Node(val);
                q.push(node -> left);
            }
            cin >> val;
            if (val != -1) {
                node -> right = new Node(val);
                q.push(node -> right);
            }        
        }
    }
    return root;
}

void print(Node* root) {
    if (!root) return;
    Node *curr = root;
    Node *next = nullptr;
    while (curr) {
        next = nullptr;
        while (curr) {
            cout << curr -> val << ' ';
            if (!next) {
                if (curr -> left) next = curr -> left;
                else if (curr -> right) next = curr -> right;
            } 
            curr = curr -> next;
        }
        curr = next;
        cout << '\n';
    }
}

int main() {
    Node *root = input();
    root = connect(root);
    print(root);
    return 0;
}