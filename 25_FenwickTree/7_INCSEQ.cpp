/*
Given a sequence of N (1 ≤ N ≤ 10,000) integers S1, ..., SN (0 ≤ Si < 100,000), compute the number 
of increasing subsequences of S with length K (1 ≤ K ≤ 50 and K ≤ N); that is, the number of 
K-tuples i1, ..., iK such that 1 ≤ i1 < ... < iK ≤ N and Si1 < ... < SiK.

Input
The first line contains the two integers N and K. The following N lines contain the integers of 
the sequence in order.

Output
Print a single integer representing the number of increasing subsequences of S of length K, 
modulo 5,000,000.

Sample Input
4 3
1
2
2
10

Output:
2
*/
#include <bits/stdc++.h>
using namespace std;
const int mod = 5e6;
const int maxn = 1e4 + 1;
int n, k, arr[maxn];
int tmp[maxn];
int sz, unq[maxn];
int BIT[51][maxn];
int maxval;

int b_search(int x) {
    int l = 0, r = sz - 1, mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (unq[mid] == x) break;
        else if (unq[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return mid + 1;
}

void update(int k, int i, int val) {
    while (i <= n) {
        BIT[k][i] += val;
        if (BIT[k][i] > mod) BIT[k][i] -= mod;
        i += (i & (-i));
    }
}

int query(int k, int i) {
    int sum = 0;
    while (i > 0) {
        sum += BIT[k][i];
        if (sum > mod) sum -= mod;
    	i -= (i & (-i));
    }
    return sum;
}

int main() {
    cin >> n >> k;
	int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        tmp[i] = arr[i];
    }
    sort(tmp, tmp + n);
    unq[0] = tmp[0]; sz = 1;
    for (int i = 1; i < n; i++) {
        if (tmp[i] != tmp[i - 1]) {
            unq[sz++] = tmp[i];
        }
    }
    for (int i = 0; i < n; i++) {
        arr[i] = b_search(arr[i]);
    }    
    for (int i = 0; i < n; i++) {
        update(1, arr[i], 1);
        for (int j = 2; j <= min(i + 1, k); j++) {
            int s = query(j - 1, arr[i] - 1);
            update(j, arr[i], s);
        }
    }

    cout << query(k, n) << '\n';
}