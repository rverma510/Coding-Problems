#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);
#define rf freopen("input.txt", "r", stdin);
#define wf freopen("output.txt", "w", stdout);
int q;
struct node {
    int id;
    int pos;
    node *left;
    node *right;
    node(int id, int pos): id(id), pos(pos), left(NULL), right(NULL) {}
};
node* insert(node *root, int id, int pos) {
    if (root == NULL) {
        cout << pos << "\n";
        root = new node(id, pos);
        return root;
    }
    if (id < root->id) {
        root->left = insert(root->left, id, 2 * pos);
    }
    else if (id > root->id) {
        root->right = insert(root->right, id, 2 * pos + 1);
    }
    return root;
}
node *del(node *root, int id, bool check) {
    if (root == NULL) {
        return root;
    }
    if (id < root->id) {
        root->left = del(root->left, id, check);
    }
    else if (id > root->id) {
        root->right = del(root->right, id, check);
    }
    else {
        if (check) {
            cout << root->pos << "\n";
        }
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL) {
            node *replace = root->left;
            delete root;
            return replace;
        }
        else if (root->left == NULL && root->right != NULL) {
            node *replace = root->right;
            delete root;
            return replace;
        }
        else {
            node* replace = root->right;
            while (replace->left != NULL)
                replace = replace->left;
            root->id = replace->id;
            root->right = del(root->right, replace->id, false);
            return root;
        }
    }
    return root;
}
int main() {
    speed;
    node *root = NULL;
    cin >> q;
    while (q--) {
        char ch; int n;
        cin >> ch >> n;
        if (ch == 'i') {
            root = insert(root, n, 1);
        }
        else {
            root = del(root, n, true);
        }
    }
    return 0;
}
