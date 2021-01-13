#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int maxn = 1e8;
int n;

// bool prime[maxn];
// void sieve() {
//     memset(prime, true, sizeof(prime));
//     prime[0] = prime[1] = false;
//     for (int i = 2; i * i < maxn; i++) {
//         if (prime[i]) {
//             for (int j = i * i; j < maxn; j += i) prime[j] = false;
//         }
//     }
// }

bool isprime(int num) {
    for (int i = 3; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void gen(int num, int n) {
    if (n == 0) {
        cout << num << '\n'; 
        return;
    }
    for (int i = 1; i <= 9; i += 2) {
        if (!isprime(num * 10 + i)) continue;
        gen(num * 10 + i, n - 1);
    }
}

void generate() {
    gen(2, n - 1);
    gen(3, n - 1);
    gen(5, n - 1);
    gen(7, n - 1);
}

int main() {
    // sieve();
    speed;
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    cin >> n;
    generate();
    return 0;
}