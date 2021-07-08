/*
In this problem, you have to maintain a dynamic set of numbers which support the two fundamental 
operations

INSERT(S,x): if x is not in S, insert x into S
DELETE(S,x): if x is in S, delete x from S

and the two type of queries

K-TH(S) : return the k-th smallest element of S
COUNT(S,x): return the number of elements of S smaller than x

Input Format
Line 1: Q (1 ≤ Q ≤ 200000), the number of operations
In the next Q lines, the first token of each line is a character I, D, K or C meaning that the 
corresponding operation is INSERT, DELETE, K-TH or COUNT, respectively, following by a whitespace 
and an integer which is the parameter for that operation.
If the parameter is a value x, it is guaranteed that ≤ |x| ≤ 10^9. If the parameter is an index k,
it is guaranteed that 1 ≤ k ≤ 10^9.`

Output
For each query, print the corresponding result in a single line. In particular, for the queries 
K-TH, if k is larger than the number of elements in S, print the word 'invalid'.

Input Format
8
I -1
I -1
I 2
C 0
K 2
D -1
K 1
K 2

Output Format
1
2
2
invalid
*/

#include <bits/stdc++.h>
using namespace std;

struct Query {
    char ch;
    int x;
};

void update(int i, int add, int n, int *BIT) {
    while (i <= n) {
        BIT[i] += add;
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
 
int main(){
    int q;
    cin >> q;
    Query query[q];
    set<int> s;
    vector<int> arr;
    arr.push_back(INT_MIN);
	for (int i = 0; i < q; i++) {
        char ch;
        int x;
        cin >> ch >> x;
        query[i].ch = ch;
        query[i].x = x;
        if ((ch == 'I' || ch == 'D' || ch == 'C') && s.find(x) == s.end()) {
            arr.push_back(x);
            s.insert(x);
        }
    }
    s.clear();
    sort(arr.begin(), arr.end());
    int n = arr.size() - 1;
    map<int, int> m;
    for (int i = 1; i <= n; i++) {
        m[arr[i]] = i;
    }
    int *BIT = new int[n + 1]();
    for (int i = 0; i < q; i++) {
        char ch = query[i].ch;
        int x = query[i].x;
        if (query[i].ch == 'I') {
            int idx = m[x];
            if (count(idx, BIT) == count(idx - 1, BIT)) {
                update(idx, 1, n, BIT);
            }
        }
        else if (query[i].ch == 'D') {
            int idx = m[x];
            if (count(idx, BIT) != count(idx - 1, BIT)) {
                update(idx, -1, n, BIT);
            }
        }
        else if (query[i].ch == 'K') {
            int l = 1, r = n;
            int ans = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                int c = count(mid, BIT);
                if (c == x) {
                    ans = arr[mid];
                    r = mid - 1;
                }
                else if (c > x) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            if (ans != -1)cout << ans << '\n';
            else cout << "invalid\n";
        }
        else if (query[i].ch == 'C') {
            int idx = m[x] - 1;
            cout << count(idx, BIT) << '\n';
        }
    }
    delete [] BIT;
    return 0;
}
