/*
World is getting more evil and it's getting tougher to get into the Evil League of Evil. Since the legendary Bad Horse has retired, now you have 
to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). You are given an array of N 
elements, which are initially all 0. After that you will be given C commands. They are -
0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.

1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
Input
In the first line you'll be given T, number of test cases.

Each test case will start with N (N <= 100 000) and C (C <= 100 000). After that you'll be given C commands in the format as mentioned above. 
1 <= p, q <= N and 1 <= v <= 10^7.

Output
Print the answers of the queries.

Input:
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8

Output:
80  
508
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void updateLazy(ll *tree, ll *lazy, ll start, ll end, ll treeIndex, ll left, ll right, ll inc) {
    if(start > end) {
        return;
    }
    if(lazy[treeIndex] != 0) {
        tree[treeIndex] += lazy[treeIndex] * (end - start + 1);
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
        tree[treeIndex] += inc * (end - start + 1);
        if(start != end) {
            lazy[2 * treeIndex] += inc;
            lazy[2 * treeIndex + 1] += inc;
        }
        return;
    }
    ll mid = start + (end - start) / 2;
    updateLazy(tree, lazy, start, mid, 2 * treeIndex, left, right, inc);
    updateLazy(tree, lazy, mid + 1, end, 2 * treeIndex + 1, left, right, inc);
    tree[treeIndex] = tree[2 * treeIndex] + tree[2 * treeIndex + 1];
}

ll query(ll *tree, ll *lazy, ll start, ll end, ll treeIndex, ll left, ll right) {
    if(start > end) {
        return 0;
    }
    if(lazy[treeIndex] != 0) {
        tree[treeIndex] += lazy[treeIndex] * (end - start + 1);
        if(start != end) {
            lazy[2 * treeIndex] += lazy[treeIndex];
            lazy[2 * treeIndex + 1] += lazy[treeIndex];
        }
        lazy[treeIndex] = 0;
    }
    if(start > right || end < left) {
        return 0;
    }
    if(start >= left && end <= right) {
        return tree[treeIndex];
    }
    ll mid = start + (end - start) / 2;
    ll ans1 = query(tree, lazy, start, mid, 2 * treeIndex, left, right);
    ll ans2 = query(tree, lazy, mid + 1, end, 2 * treeIndex + 1, left, right);
    return ans1 + ans2;
}

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n, c, type, p, q, v;
        cin>>n>>c;
        ll *tree = new ll[3 * n]();
        ll *lazy = new ll[3 * n]();
        while(c--) {
            cin>>type>>p>>q;
            if(type == 0) {
                cin>>v;
                updateLazy(tree, lazy, 0, n - 1, 1, p - 1, q - 1, v);
            }
            else {
                cout<<query(tree, lazy, 0, n - 1, 1, p - 1, q - 1)<<endl;
            }
        }
    }
    return 0;
}