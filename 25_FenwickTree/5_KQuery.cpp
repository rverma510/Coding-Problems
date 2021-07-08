/*
Given a sequence of n numbers a1, a2, ..., an and a number of k- queries. A k-query is a triple 
(i, j, k) (1 ≤ i ≤ j ≤ n). For each k-query (i, j, k), you have to return the number of elements 
greater than k in the subsequence ai, ai+1, ..., aj.

Input Format
Line 1: n (1 ≤ n ≤ 30000).
Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^9).
Line 3: q (1 ≤ q ≤ 200000), the number of k- queries.
In the next q lines, each line contains 3 numbers i, j, k representing a k-query 
(1 ≤ i ≤ j ≤ n, 1 ≤ k ≤ 10^9).

Output Format
For each k-query (i, j, k), print the number of elements greater than k in the subsequence ai, 
ai+1, ..., aj in a single line.

Sample Input
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2 

Sample Output
2
0
3 
*/
#include<bits/stdc++.h>
using namespace std;

struct Elem {
	int x, idx;  
};

struct Query {
    int x, y, z, idx;
};

bool compare1(const Elem &a, const Elem &b) {
    return a.x > b.x;
}

bool compare2(const Query &a, const Query &b) {
    return a.z > b.z;
}

void update(int i, int n, int *BIT) {
    while (i <= n) {
        BIT[i]++;
        i += (i & (-i));
    }
}

int count(int i, int *BIT) {
    int c = 0;
    while (i > 0) {
        c += BIT[i];
        i -= (i & (-i));
    }
    return c;
}

int main() {
    int n, q;
    cin >> n;
    Elem *elem = new Elem[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> elem[i].x;
        elem[i].idx = i;
    }
    sort(elem + 1, elem + n + 1, compare1);
    cin >> q;
    Query *query = new Query[q];
    for (int i = 0; i < q; i++) {
        cin >> query[i].x >> query[i].y >> query[i].z;
        query[i].idx = i;
    }
    sort(query, query + q, compare2);
    int *BIT = new int[n + 1]();
    int *ans = new int[q];
    int j = 1;
    for (int i = 0; i < q; i++) {
        while (j <= n && elem[j].x > query[i].z) {
            update(elem[j].idx, n, BIT);
            j++;
        }
        ans[query[i].idx] = count(query[i].y, BIT) - count(query[i].x - 1, BIT);
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
    
    delete [] elem;
    delete [] query;
    delete [] BIT;
    delete [] ans;
	return 0;
}
