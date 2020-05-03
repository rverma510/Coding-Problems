/*
Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence. He gives him an array of N natural 
numbers and asks him to solve the following queries:-
Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.

Input:
First line of the input contains the number N. Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y. 

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.

Constraints:
1<=N,Q<=10^5

1<=l<=r<=N 

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9

Note:-
indexing starts from 1.

Sample Input
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6

Sample Output
2
2
4
*/
#include<bits/stdc++.h>
using namespace std;
void buildTree(int *arr, int *tree, int start, int end, int treeIndex){
    if(start == end){
        tree[treeIndex] = arr[start] % 2;
        return;
    }
    int mid = start + (end - start) / 2;
    buildTree(arr, tree, start, mid, 2 * treeIndex);
    buildTree(arr, tree, mid + 1, end, 2 * treeIndex + 1);
    tree[treeIndex] =  tree[2 * treeIndex] + tree[2 * treeIndex + 1];
}
void updateTree(int *arr, int *tree, int start, int end, int treeIndex, int idx, int value){
    if(start == end){
        arr[idx] = value;
        tree[treeIndex] = arr[idx] % 2;
        return;
    }
    int mid = start + (end - start) / 2;
    if(idx > mid)
        updateTree(arr, tree, mid + 1, end, 2 * treeIndex + 1, idx, value);
    else
        updateTree(arr, tree, start, mid, 2 * treeIndex, idx, value);
    tree[treeIndex] =  tree[2 * treeIndex] + tree[2 * treeIndex + 1];
}
int query(int *tree, int start, int end, int treeIndex, int left, int right){
    if(start > right || end < left){
        return 0;
    }
    if(start >= left && end <= right){
        return tree[treeIndex];
    }
    int mid = start + (end - start) / 2;
    int res1 = query(tree, start, mid, 2 * treeIndex, left, right);
    int res2 = query(tree, mid + 1, end, 2 *treeIndex + 1, left, right);
    return res1 + res2; 
}
int main(){
    int n, q, type, x, y;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int *tree = new int[4 * n];
    buildTree(arr, tree, 0, n - 1, 1);
    // for(int i = 1; i < 4 * n; i++){
    //     cout<<tree[i]<<" ";
    // }
    // cout<<endl;
    cin>>q;
    while(q--){
        cin>>type>>x>>y;
        if(type == 0){
            updateTree(arr, tree, 0, n - 1, 1, x - 1, y);
        }
        else{
            int res = query(tree, 0, n -1, 1, x - 1, y - 1);
            if(type == 1)
                cout<<(y - x + 1 - res)<<endl;
            else
                cout<<res<<endl;
        }
    }
    return 0;
}