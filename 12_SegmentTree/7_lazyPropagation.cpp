#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int treeIndex) {
    if(start == end){
        tree[treeIndex] = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    buildTree(arr, tree, start, mid, 2 * treeIndex);
    buildTree(arr, tree, mid + 1, end, 2 * treeIndex + 1);
    tree[treeIndex] = min(tree[2 * treeIndex], tree[2 * treeIndex + 1]);
}

void updateSegmentTreeLazy(int *tree, int *lazy, int start, int end, int treeIndex, int left, int right, int inc) {
    if(start > end) {
        return;
    }
    if(lazy[treeIndex] != 0) {
        tree[treeIndex] += lazy[treeIndex];
        if(start != end) {
            lazy[2 * treeIndex] += lazy[treeIndex];
            lazy[2 * treeIndex + 1] += lazy[treeIndex];
        }
        lazy[treeIndex] = 0; 
    }
    if(start > right || end < left) {
        return;
    }
    if(start >= left && end <= right) {
        tree[treeIndex] += inc;
        if(start != end) {
            lazy[2 * treeIndex] += inc;
            lazy[2 * treeIndex + 1] += inc;
        }
        return;
    }
    int mid = start + (end - start) / 2;
    updateSegmentTreeLazy(tree, lazy, start, mid, 2 * treeIndex, left, right, inc);
    updateSegmentTreeLazy(tree, lazy, mid + 1, end, 2 * treeIndex + 1, left, right, inc);
    tree[treeIndex] = min(tree[2 * treeIndex], tree[2 * treeIndex + 1]);
}

int querySegmentTreeLazy(int *tree, int *lazy, int start, int end, int treeIndex, int left, int right) {
    if(start > end) {
        return INT_MAX;
    }
    if(lazy[treeIndex] != 0) {
        tree[treeIndex] += lazy[treeIndex];
        if(start != end) {
            lazy[2 * treeIndex] += lazy[treeIndex];
            lazy[2 * treeIndex + 1] += lazy[treeIndex];
        }
        lazy[treeIndex] = 0;
    }
    if(start > right || end < left) {
        return INT_MAX;
    }
    if(start >= left && end <= right) {
        return tree[treeIndex];
    }
    int mid = start + (end - start) / 2;
    int ans1 = querySegmentTreeLazy(tree, lazy, start, mid, 2 * treeIndex, left, right);
    int ans2 = querySegmentTreeLazy(tree, lazy, mid + 1, end, 2 * treeIndex + 1, left, right);
    return min(ans1, ans2);
}

int main() {
    int n = 4;
    int arr[] = {1, 3, -2, 4};
    int *tree = new int[4 * n];
    buildTree(arr, tree, 0, n - 1, 1);
    int *lazy = new int[4 * n]();
    updateSegmentTreeLazy(tree, lazy, 0, n - 1, 1, 0, 3, 3);
    updateSegmentTreeLazy(tree, lazy, 0, n - 1, 1, 0, 1, 2);
    cout<<"Segment Tree :"<<endl;
    for(int i = 1; i < 4 * n; i++) {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    cout<<"Lazy Tree :"<<endl;
    for(int i = 1; i < 4 * n; i++) {
        cout<<lazy[i]<<" ";
    }
    cout<<endl;
    cout<<querySegmentTreeLazy(tree, lazy, 0, n - 1, 1, 0, 1)<<endl;
    cout<<querySegmentTreeLazy(tree, lazy, 0, n - 1, 1, 1, 2)<<endl;
    return 0;
}
