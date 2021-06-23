#include<bits/stdc++.h>
using namespace std;

const int maxn = 101;
bool prime[maxn];
int p[maxn];
int cnt;

void sieve() {
    cnt = 0;
    memset(prime, true, maxn);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < maxn; i++) {
        if (prime[i]) {
            for (int j = i * i; j < maxn; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i < maxn; i++) {
        if (prime[i]) p[cnt++] = i;
    }
}

const int sz = 1e6 + 10;
int num[sz];
void helper() {
	for (int i = 0; i < cnt; i++) {
        int tmp = p[i] * p[i] * p[i];
        int fac = tmp;
        while (!(tmp > sz)) {
            num[tmp] = -1;
            tmp += fac;
        }
    }
    int j = 0;
    for (int i = 0; i < sz; i++) {
        if (num[i] != -1) {
            num[i] = j;
            j++;
        }	
    }
}

int main(){
    sieve();
    helper();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        cout << "Case " << i << ": "; 
        if (num[n] != -1) cout << num[n] << '\n';
        else cout << "Not Cube Free\n";
    }
	return 0;
}