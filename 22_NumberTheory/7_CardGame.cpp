#include<bits/stdc++.h>
using namespace std;
#define test cout<<"Test\n" 

typedef long long int ll;
typedef pair<int, int> pii;

const int maxn = 1e5 + 10;
int arr[maxn];
vector<pii> fac_k;
vector<pii> curr;
void factors_k(int k) {
    for (int i = 2; i * i <= k; i++) {
        int cnt = 0;
        while (!(k % i)) {
            k /= i;
            cnt++;
        }
        if (cnt) {
            fac_k.push_back({i, cnt});
            curr.push_back({i, 0});
        }
    }
    if (k > 1) {
        fac_k.push_back({k, 1});
        curr.push_back({k, 0});
    }
}

bool check() {
    for (int i = 0; i < fac_k.size(); i++) {
        if (fac_k[i].second > curr[i].second) return false;
    }
    return true;
}

void add(int num) {
    for (int i = 0; i < fac_k.size(); i++) {
        int f = fac_k[i].first;
        int cnt = 0;
        while (!(num % f)) {
            num /= f;
            cnt++;
        }
        curr[i].second += cnt;
    }
}

void sub(int num) {
    for (int i = 0; i < fac_k.size(); i++) {
        int f = fac_k[i].first;
        int cnt = 0;
        while (!(num % f)) {
            num /= f;
            cnt++;
        }
        curr[i].second -= cnt;
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    factors_k(k);
    int i = -1, j = 0;
    ll ans = 0;
    while (j < n) {
    	while(!check() && i < n) {
            i++; 
            if (i == n) break;
            add(arr[i]);
            
        }
        ans += (n - i);
        sub(arr[j]);
        j++;
    }
    cout << ans << '\n';
	return 0;
}