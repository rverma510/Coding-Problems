/*
Daulat Ram is an affluent business man. After demonetization, IT raid was held at his accommodation
in which all his money was seized. He is very eager to gain his money back, he started investing 
in certain ventures and earned out of them. On the first day, his income was Rs. X, followed by 
Rs. Y on the second day. Daulat Ram observed his growth as a function and wanted to calculate his 
income on the Nth day.
The function he found out was FN = FN-1 + FN-2 + FN-1×FN-2
Given his income on day 0 and day 1, calculate his income on the Nth day (yeah Its that simple).

Input:
The first line of input consists of a single integer T denoting number of test cases.
Each of the next T lines consists of three integers F0, F1 and N respectively.

Output:
For each test case, print a single integer FN, as the output can be large, calculate the answer modulo 10^9+7.

CONSTRAINTS:
1 ≤ T ≤ 10^5
0 ≤ F0, F1, N ≤ 10^9

Sample Input :
2
0 1 2
1 2 4

Sample Output:
1
107

Explanation
In the second test case his income on day 0 is 1 and the income on day 1 is 2. We need to 
calculate his income on day 4.
F0=1
F1=2
F2=1 + 2 + 1×2 = 5
F3=2 + 5 + 2×5 = 17
F4=5 + 17 + 5×17 = 107
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;

int power(int a, int b) {
    if (a == 0) return 0;
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = (a * 1ll * a) % mod;
        b >>= 1;
    }
    return res;
}

void multiply(int A[2][2], int B[2][2]) {
    int C[2][2];
    memset(C, 0, sizeof(C));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C[i][j] = (C[i][j] + A[i][k] * 1ll * B[k][j]) % (mod - 1);
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            A[i][j] = C[i][j] % (mod - 1);
        }
    }
}

void powerFibo(int A[2][2], int n) {
    if (n == 0 || n == 1) return;
    powerFibo(A, n / 2);
    multiply(A, A);
    if (n % 2) {
        int B[2][2] = {{1, 1}, {1, 0}};
        multiply(A, B);
    }
}

pii fibo(int n) {
    int A[2][2] = {{1, 1}, {1, 0}};
    powerFibo(A, n - 1);
    return {A[0][1] % (mod - 1), A[0][0] % (mod - 1)};
}

int main() {
	
    int t;
    cin >> t;
    while (t--) {
        int f0, f1, n;
        cin >> f0 >> f1 >> n;
        if (n == 0) {
            cout << f0 << '\n';
        	continue;
        }
        if (n == 1) {
            cout << f1 << '\n';
            continue;
        }
        pii pr = fibo(n);
        int a_pow = pr.first;
        int b_pow = pr.second;
        ll res = 1;
        res = (res * power(f0 + 1, a_pow)) % mod;
        res = (res * power(f1 + 1, b_pow)) % mod;
        cout << res - 1 << '\n';
    }
    return 0;
}