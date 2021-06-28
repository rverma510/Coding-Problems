#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int mod = 1e9 + 7;

// void multiply(ull A[3][3], ull B[3][3]) {
//     ull C[3][3];
//     memset(C, 0, sizeof(C));
// 	for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             for (int k = 0; k < 3; k++) {
//                 C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
//             }
//         }
//     }
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             A[i][j] = C[i][j];
//         }
//     }
// }

// void power(ull A[3][3], ull x) {
//     if (x == 0 || x == 1) return;
//     power(A, x / 2);
//     multiply(A, A);
    
//     if (x % 2) {
//         ull B[3][3] = {{1, 1, 0}, {0, 1, 1}, {0, 1, 0}};
//         multiply(A, B);
//     }
// }

// ull fiboSumHelper(ull x) {
//     if (x == 0) return 0;
// 	ull A[3][3] = {{1, 1, 0}, {0, 1, 1}, {0, 1, 0}};
//     power(A, x);
//     return A[0][1] % mod;
// } 

// unsigned long long fiboSum(unsigned long long m,unsigned long long n) {
// 	ull ans1 = 0;
//     if (m > 0) ans1 = fiboSumHelper(m - 1);
//     ull ans2 = fiboSumHelper(n);
//     return (ans2 - ans1 + mod) % mod; 
        
// }

void multiply(ull A[2][2], ull B[2][2]) {
    ull C[2][2];
    memset(C, 0, sizeof(C));
	for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            A[i][j] = C[i][j] % mod;
        }
    }
}

void power(ull A[2][2], int n) {
    if (n == 0 || n == 1) return;
    power(A, n / 2);
    multiply(A, A);
    if (n % 2) {
        ull M[2][2] = {{1, 1}, {1, 0}};
        multiply(A, M);
    }
}

ull fibo(ull n) {
    if (n == 0) return 0;
    ull A[2][2] = {{1, 1}, {1, 0}};
    power(A, n - 1);
    return A[0][0] % mod;
}


unsigned long long fiboSum(unsigned long long m,unsigned long long n) {
	ull ans1 = fibo(m + 1);
    ull ans2 = fibo(n + 2);
    return (ans2 - ans1 + mod) % mod;
        
}

int main() {
    unsigned long long m, n;
    cin >> m >> n;
	cout << fiboSum(m, n) << '\n';
    return 0;
}

