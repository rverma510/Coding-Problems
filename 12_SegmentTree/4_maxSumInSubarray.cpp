/*
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.

Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.

Output
Your program should output the results of the M queries, one 
query per line.

Sample Input:
3 
-1 2 3 
1
1 2

Sample Output:
2
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct node{
    ll maxSum;
    ll sum;
    ll bestPrefixSum;
    ll bestSuffixSum;
};
void buildTree(int *arr, node *tree, int start, int end, int treeIndex){
    if(start == end){
        tree[treeIndex].maxSum = arr[start];
        tree[treeIndex].sum = arr[start];
        tree[treeIndex].bestPrefixSum = arr[start];
        tree[treeIndex].bestSuffixSum = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    buildTree(arr, tree, start, mid, 2 * treeIndex);
    buildTree(arr, tree, mid + 1, end, 2 * treeIndex + 1);
    node left = tree[2 * treeIndex];
    node right = tree[2 * treeIndex + 1]; 
    tree[treeIndex].maxSum = max(left.maxSum, 
                                max(right.maxSum, 
                                    max(left.sum + right.bestPrefixSum, 
                                        max(right.sum + left.bestSuffixSum, left.bestSuffixSum + right.bestPrefixSum)
                                    )
                                )
                            );
    tree[treeIndex].sum = left.sum + right.sum;
    tree[treeIndex].bestPrefixSum = max(left.bestPrefixSum, left.sum + right.bestPrefixSum);
    tree[treeIndex].bestSuffixSum = max(right.bestSuffixSum, right.sum + left.bestSuffixSum);
}
node* query(node *tree, int start, int end, int treeIndex, int left, int right){
    if(start > right || end < left){
        node *res = new node;
        res->maxSum = INT_MIN;
        res->sum = INT_MIN;
        res->bestPrefixSum = INT_MIN;
        res->bestSuffixSum = INT_MIN;
        return res;
    }
    if(start >= left && end <= right){
        node *res = new node;
        res->maxSum = tree[treeIndex].maxSum;
        res->sum = tree[treeIndex].sum;
        res->bestPrefixSum = tree[treeIndex].bestPrefixSum;
        res->bestSuffixSum = tree[treeIndex].bestSuffixSum;
        return res;
    }
    int mid = start + (end - start) / 2;
    node *res1 = query(tree, start, mid, 2 * treeIndex, left, right);
    node *res2 = query(tree, mid + 1, end, 2 * treeIndex + 1, left, right);
    node *res = new node;
    res->maxSum = max(res1->maxSum, 
                                max(res2->maxSum, 
                                    max(res1->sum + res2->bestPrefixSum, 
                                        max(res2->sum + res1->bestSuffixSum, res1->bestSuffixSum + res2->bestPrefixSum)
                                    )
                                )
                            );
    res->sum = res1->sum + res2->sum;
    res->bestPrefixSum = max(res1->bestPrefixSum, res1->sum + res2->bestPrefixSum);
    res->bestSuffixSum = max(res2->bestSuffixSum, res2->sum + res1->bestSuffixSum);
    delete res1;
    delete res2;
    return res;

}
int main(){
    int n, m, x, y;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    node *tree = new node[4 * n];
    buildTree(arr, tree, 0, n - 1, 1);
    // for(int i = 1; i < 2*n; i++){
    //     cout<<tree[i].maxSum<<" "<<tree[i].sum<<" "<<tree[i].bestPrefixSum<<" "<<tree[i].bestSuffixSum<<" "<<endl;
    // }
    // cout<<endl;
    cin>>m;
    while(m--){
        cin>>x>>y;
        node *res = query(tree, 0, n - 1, 1, x - 1, y - 1);
        cout<<res->maxSum<<endl;
        delete res;
    }
    delete [] arr;
    delete [] tree;
    return 0;
}