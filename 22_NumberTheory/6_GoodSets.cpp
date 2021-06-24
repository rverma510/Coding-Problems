#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;

const int maxn = 1e6 + 10;
ll arr[maxn];

void clearArray() {
    for (int i = 0; i < maxn; i++) arr[i] = 0;
}

ll sieve() {
    for (int i = 1; i < maxn; i++) {
        if (arr[i]) {
            for (int j = 2 * i; j < maxn; j += i) {
                if (!arr[j]) continue;
                arr[j] = (arr[j] + arr[i]) % mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i < maxn; i++) {
        ans = (ans + arr[i]) % mod;
    }
    return ans;
}

int main(){
	int t;
    cin >> t;
    while (t--) {
        clearArray();
        int n;
        cin >> n;
        for (int tmp, i = 0; i < n; i++) {
            cin >> tmp;
            arr[tmp] = 1;
        }
        cout << sieve() << '\n';
    }
	return 0;
}