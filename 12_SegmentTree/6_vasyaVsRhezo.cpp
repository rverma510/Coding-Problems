/*
Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by 
numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a 
range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, 
she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B 
value, she chooses the one with lower index in line.
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.

Input:
First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.

Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should choose.

Constraints:
1≤ N,Q ≤10^6
1≤ Ai,Bi ≤10^9
1≤Li≤Ri

Sample Input
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5

Sample Output
2
2
4
5
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
    int idx;
    int A, B;
};
bool comp(node left, node right){
    if(left.A != right.A)
        return left.A > right.A;
    else if(left.B != right.B)
        return left.B < right.B;
    else
        return left.idx < right.idx;
}
void buildTree(int *A, int *B, node *tree, int start, int end, int treeIndex){
    if(start == end){
        tree[treeIndex].idx = start + 1;
        tree[treeIndex].A = A[start];
        tree[treeIndex].B = B[start];
        return;
    }
    int mid = start + (end - start) / 2;
    buildTree(A, B, tree, start, mid, 2 * treeIndex);
    buildTree(A, B, tree, mid + 1, end, 2 * treeIndex + 1);
    node left = tree[2 * treeIndex];
    node right = tree[2 * treeIndex + 1];
    if(comp(left, right))
        tree[treeIndex] = left;
    else
        tree[treeIndex] = right;
}
node query(node *tree, int start, int end, int treeIndex, int left, int right){
    if(start > right || end < left){
        node res;
        res.idx = INT_MAX;
        res.A = INT_MIN;
        res.B = INT_MAX;
        return res;
    }
    if(start >= left && end <= right){
        return tree[treeIndex];
    }
    int mid = start + (end - start) / 2;
    node res1 = query(tree, start, mid, 2 * treeIndex, left, right);
    node res2 = query(tree, mid + 1, end, 2 * treeIndex + 1, left, right);
    if(comp(res1, res2))
        return res1;
    else
        return res2;
}
int main(){
    int n, q, x, y;
    cin>>n;
    int *A = new int[n];
    int *B = new int[n];
    for(int i = 0; i < n; i++)
        cin>>A[i];
    for(int i = 0; i < n; i++)
        cin>>B[i];
    node *tree = new node[4 * n];
    buildTree(A, B, tree, 0, n - 1, 1);
    // for(int i = 1; i < 4 * n; i++){
    //     cout<<tree[i].idx<<" "<<tree[i].A<<" "<<tree[i].B<<endl;
    // }
    // cout<<endl;
    cin>>q;
    while(q--){
        cin>>x>>y;
        node res = query(tree, 0, n - 1, 1, x - 1, y - 1);
        cout<<res.idx<<endl;
    }
    return 0;
}