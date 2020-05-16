/*
Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)), and update ranges 
in O(lg(n)) as well. In this problem you will compute something much harder:
The sum of squares over a range with range updates of 2 types:
1) increment in a range
2) set all numbers the same in a range.

Input
There will be T (T <= 25) test cases in the input file. First line of the input contains two positive integers, N (N <= 100,000) and Q (Q <= 100,000). 
The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:

2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).

1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).

0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).

Output
For each test case output the “Case <caseno>:” in the first line and from the second line output the sum of squares for each operation of type 2. Intermediate overflow will not 
occur with proper use of 64-bit signed integer.

Input:
2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
1 1
1
2 1 1

Output:
Case 1:
30
7
13
Case 2:
1
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct node1 {
    ll sumSquares;
    ll sums;
};

struct node2 {
    int value;
    int type;
};

void buildTree(int *arr, node1 *tree, int start, int end, int treeIndex) {
    if (start == end) {
        tree[treeIndex].sumSquares = arr[start] * arr[start];
        tree[treeIndex].sums = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    buildTree(arr, tree, start, mid, 2 * treeIndex);
    buildTree(arr, tree, mid + 1, end, 2 * treeIndex + 1);
    tree[treeIndex].sumSquares = tree[2 * treeIndex].sumSquares + tree[2 * treeIndex + 1].sumSquares;
    tree[treeIndex].sums = tree[2 * treeIndex].sums + tree[2 * treeIndex + 1].sums;
}

void update(node1 *tree, node2* lazy, int start, int end, int treeIndex, int left, int right, int x, int type) {
    if (start > end) {
        return;
    }
    if (lazy[treeIndex].value != 0) {
        int y = lazy[treeIndex].value;
        if (lazy[treeIndex].type == 1) {
            tree[treeIndex].sumSquares = y * y * (end - start + 1);
            tree[treeIndex].sums = y * (end - start + 1);
            if(start != end) {
                lazy[2 * treeIndex].value = y;
                lazy[2 * treeIndex].type = lazy[treeIndex].type;
                lazy[2 * treeIndex + 1].value = y;
                lazy[2 * treeIndex + 1].type = lazy[treeIndex].type; 
            }
        }
        else {
            tree[treeIndex].sumSquares += y * y * (end - start + 1) + 2 * tree[treeIndex].sums * y;
            tree[treeIndex].sums += y * (end - start + 1);
            if(start != end) {
                lazy[2 * treeIndex].value += y;
                lazy[2 * treeIndex].type = lazy[treeIndex].type;
                lazy[2 * treeIndex + 1].value += y;
                lazy[2 * treeIndex + 1].type = lazy[treeIndex].type; 
            }
        }
        lazy[treeIndex].value = 0;
        lazy[treeIndex].type = 0;
    }
    if (start > right || end < left) {
        return;
    }
    if (start >= left && end <= right) {
        if (type == 1) {
            tree[treeIndex].sumSquares = x * x * (end - start + 1);
            tree[treeIndex].sums = x * (end - start + 1);
            if (start != end) {
                lazy[2 * treeIndex].value = x;
                lazy[2 * treeIndex].type = type;
                lazy[2 * treeIndex + 1].value = x;
                lazy[2 * treeIndex + 1].type = type; 
            }
        }
        else {
            tree[treeIndex].sumSquares += x * x * (end - start + 1) + 2 * tree[treeIndex].sums * x;
            tree[treeIndex].sums += x * (end - start + 1);
            if(start != end) {
                lazy[2 * treeIndex].value += x;
                lazy[2 * treeIndex].type = lazy[treeIndex].type;
                lazy[2 * treeIndex + 1].value += x;
                lazy[2 * treeIndex + 1].type = lazy[treeIndex].type; 
            }
        }
        return;
    }
    int mid = start + (end - start) / 2;
    update(tree, lazy, start, mid, 2 * treeIndex, left, right, x, type);
    update(tree, lazy, mid + 1, end, 2 * treeIndex + 1, left, right, x, type);
    tree[treeIndex].sumSquares = tree[2 * treeIndex].sumSquares + tree[2 * treeIndex + 1].sumSquares;
    tree[treeIndex].sums = tree[2 * treeIndex].sums + tree[2 * treeIndex + 1].sums;
}

node1 query(node1 *tree, node2 *lazy, int start, int end, int treeIndex, int left, int right) {
    if (start > end) {
        node1 res;
        res.sumSquares = 0;
        res.sums = 0;
        return res;
    }
    if (lazy[treeIndex].value != 0) {
        int y = lazy[treeIndex].value;
        if (lazy[treeIndex].type == 1) {
            tree[treeIndex].sumSquares = y * y * (end - start + 1);
            tree[treeIndex].sums = y * (start - end + 1);
            if(start != end) {
                lazy[2 * treeIndex].value = y;
                lazy[2 * treeIndex].type = lazy[treeIndex].type;
                lazy[2 * treeIndex + 1].value = y;
                lazy[2 * treeIndex + 1].type = lazy[treeIndex].type; 
            }
        }
        else {
            tree[treeIndex].sumSquares += y * y * (end - start + 1) + 2 * tree[treeIndex].sums * y;
            tree[treeIndex].sums += y * (start - end + 1);
            if(start != end) {
                lazy[2 * treeIndex].value += y;
                lazy[2 * treeIndex].type = lazy[treeIndex].type;
                lazy[2 * treeIndex + 1].value += y;
                lazy[2 * treeIndex + 1].type = lazy[treeIndex].type; 
            }
        }
        lazy[treeIndex].value = 0;
        lazy[treeIndex].type = 0;
    }
    if (start > right || end < left) {
        node1 res;
        res.sumSquares = 0;
        res.sums = 0;
        return res;
    }
    if (start >= left && end <= right) {
        return tree[treeIndex];
    }
    int mid = start + (end - start) / 2;
    node1 res1 = query(tree, lazy, start, mid, 2 * treeIndex, left, right);
    node1 res2 = query(tree, lazy, mid + 1, end, 2 * treeIndex + 1, left, right);
    node1 res;
    res.sumSquares = res1.sumSquares + res2.sumSquares;
    res.sums = res1.sums + res2.sums;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for (int i = 1; i <= t; i++) {
        cout<<"Case "<<i<<":"<<endl;
        int n, q;
        cin>>n>>q;
        int *arr = new int;
        for(int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        node1 *tree = new node1[3 * n];
        node2 *lazy = new node2[3 * n]();
        buildTree(arr, tree, 0, n - 1, 1);
        while(q--) {
            int type, left, right, x;
            cin>>type>>left>>right;
            if(type == 2) {
                node1 res = query(tree, lazy, 0, n - 1, 1, left - 1, right - 1);
                cout<<res.sumSquares<<endl;
            }
            else {
                cin>>x;
                update(tree, lazy, 0, n - 1, 1, left - 1, right - 1, x, type + 1);
            }
        }
        
    }

}