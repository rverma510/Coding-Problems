#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int maxn = 1010;

int a, b;
int arr[maxn][maxn];

bool isprime(int n) {
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void gen(int n) {
    string s = to_string(n);
    for (int i = s.size() - 2; i >= 0; i--) s += s[i];
    n = stoi(s);
    if (n >= a && n <= b && isprime(n)) cout << n << '\n';
}

void generate() {
    if (5 >= a && 5 <= b) cout << 5 << '\n';
    if (7 >= a && 7 <= b) cout << 7 << '\n';
    if (11 >= a && 11 <= b) cout << 11 << '\n';
    for (int i = 10; i <= 9999; i++) gen(i);
}

int main() {
    speed;
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    cin >> a >> b;
    generate();
    return 0;
}