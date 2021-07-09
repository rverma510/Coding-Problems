/*
Given a sequence A1 , A2 , A3 .. AN of length N . Find total number of wave subsequences having length greater than 1.
Wave subsequence of sequence A1 , A2 , A3 .. AN is defined as a set of integers i1 , i2 .. ik such that Ai1 < Ai2 > Ai3 < Ai4 .... 
or Ai1 > Ai2 < Ai3 > Ai4 .... and i1 < i2 < ...< ik.Two subsequences i1 , i2 .. ik and j1 , j2 .. jm are considered different 
if k != m or there exists some index l such that il ! = jl

INPUT
First line of input consists of integer N denoting total length of sequence.Next line consists of N integers A1 , A2 , A3 .. AN.

OUTPUT
Output total number of wave subsequences of given sequence . Since answer can be large, output it modulo 10^9+7

CONSTRAINTS
1 ≤ N ≤ 10^5
1 ≤ Ai ≤ 10^5

SAMPLE INPUT
5
1 3 5 4 2

SAMPLE OUTPUT
17

Explanation
All the possible sequences are: [ 1 3 ] , [1 5 ] , [ 1 4 ] , [1 2 ] , [1 3 2] , [1 4 2 ] , [1 5 2] , [1 5 4] , [3 5] , [3 4] , 
[3 2] , [3 5 2] , [3 4 2] , [3 5 4] , [5 4] , [5 2 ] , [4 2] . Note that value in the bracket are the values from the original 
sequence whose positions are maintained.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
int n;
int arr[maxn];
ll bit[3][maxn];
int maxval;

void update(int i, int idx, int add) {
    while (i <= maxval) {
        bit[idx][i] += add;
        bit[idx][i] %= mod;
        i += (i & (-i));
    }
}

ll query(int i, int idx) {
    ll ans = 0;
    while (i > 0) {
        ans += bit[idx][i];
        ans %= mod;
        i -= (i & (-i));
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    	maxval = max(maxval, arr[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll a = query(arr[i] - 1, 0) + query(arr[i] - 1, 2);
        a %= mod;
        ll b = query(maxval, 1) - query(arr[i], 1) + query(maxval, 2) - query(arr[i], 2);
        b = (b + mod) % mod;
        ans = (ans + a + b) % mod;
        update(arr[i], 0, b);
        update(arr[i], 1, a);
        update(arr[i], 2, 1);
    }
    cout << ans << '\n';
}