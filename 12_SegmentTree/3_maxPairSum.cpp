/*
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and 
they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].

Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of 
operations. Next Q lines contain the operations.

Output
 Output the maximum sum mentioned above, in a separate line, for each Query.

Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5

Output:
7
9
11
12
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
    int mx, secMx;
};
void buildTree(int *arr, node *tree, int start, int end, int treeNode){
    if(start == end){
        tree[treeNode].mx = arr[start];
        tree[treeNode].secMx = INT_MIN;
        return;
    }
    int mid = start + (end - start) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);
    int mx = max(tree[2 * treeNode].mx, tree[2 * treeNode + 1].mx);
    int secMx = min(max(tree[2 * treeNode].secMx, tree[2 * treeNode + 1].mx), max(tree[2 * treeNode].mx, tree[2 * treeNode + 1].secMx));
    tree[treeNode].mx = mx;
    tree[treeNode].secMx = secMx;
}
void updateTree(int *arr, node *tree, int start, int end, int treeNode, int idx, int value){
    if(start == end){
        arr[idx] = value;
        tree[treeNode].mx = value;
        tree[treeNode].secMx = INT_MIN;
        return;
    }
    int mid = start + (end - start) / 2;
    if(idx > mid){
        updateTree(arr, tree, mid + 1, end, 2 * treeNode + 1, idx, value);
    }
    else{
        updateTree(arr, tree, start, mid, 2 * treeNode, idx, value);
    }
    int mx = max(tree[2 * treeNode].mx, tree[2 * treeNode + 1].mx);
    int secMx = min(max(tree[2 * treeNode].secMx, tree[2 * treeNode + 1].mx), max(tree[2 * treeNode].mx, tree[2 * treeNode + 1].secMx));
    tree[treeNode].mx = mx;
    tree[treeNode].secMx = secMx;
}
node* query(node *tree, int start, int end, int treeNode, int left, int right){
    if(start > right || end < left){
        node *res = new node;
        res->mx = INT_MIN;
        res->secMx = INT_MIN;
        return res;
    }
    if(start >= left && end <= right){
        node *res = new node;
        res->mx = tree[treeNode].mx;
        res->secMx = tree[treeNode].secMx;
        return res;
    }
    int mid = start + (end - start) / 2;
    node *res1 = query(tree, start, mid, 2 * treeNode, left, right);
    node *res2 = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);
    node *res = new node;
    res->mx = max(res1->mx, res2->mx);
    res->secMx = min(max(res1->mx, res2->secMx), max(res1->secMx, res2->mx));
    delete res1;
    delete res2;
    return res;
}
int main(){
    int n, q;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)  
        cin>>arr[i];
    node *tree = new node[4 * n];
    buildTree(arr, tree, 0, n - 1, 1);
    cin>>q;
    while(q--){
        char ch;
        int a, b;
        cin>>ch>>a>>b;
        if(ch == 'Q'){
            node *res = query(tree, 0, n - 1, 1, a - 1, b - 1);
            cout<<(res->mx + res->secMx)<<endl;
            delete res;
        }
        else{
            updateTree(arr, tree, 0, n - 1, 1, a - 1, b);
        }
    }
    delete [] arr;
    delete [] tree;
    return 0;
}