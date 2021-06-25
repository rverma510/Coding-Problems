#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int maxn = 2e6 + 10;
int prime[maxn];
void sieve() {
	for (int i = 0; i < maxn; i++) {
        prime[i] = i;
    }    
    for (int i = 2; i * i < maxn; i++) {
        if (prime[i] == i) {
            for (int j = i * i; j < maxn; j += i) {
                if (prime[j] == j) prime[j] = i;
            }
        }
    }
}

int main() {
    sieve();
	int n; 
    cin >> n;
    vector<bool> num(n + 1, false);
    for (int i = n; i > 0; i--) {
        if (num[i]) continue;
        vector<int> arr;
        arr.pb(i);
        int x = i;
        while (x != 1) {
            int p = prime[x];
            int tmp = i - p;
            while (tmp >= p) {
                if (!num[tmp]) {
                    arr.pb(tmp);
                    num[tmp] = true;
                }
                tmp -= p;
            }
            while (!(x % p)) {
                x /= p;
            }
        }
        sort(arr.begin(), arr.end(), [](int a, int b) { return a > b; });
        for (int &i: arr) {
            cout << i << ' ';
        }
    }
    cout << '\n';
}