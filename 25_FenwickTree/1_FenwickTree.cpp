#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 1e6 + 10;

int n;
ll tree[maxn] = {0};

void update(int i, ll add) {
    while (i <= n) {
        tree[i] += add;
        i += (i & -i);
    }
}

ll sum(int i) {
    ll s = 0;
    while (i > 0) {
        s += tree[i];
        i -= (i & -i);
    }
    return s;
}

ll rangeQuery(int l, int r) {
    return sum(r) - sum(l - 1);
}

int main() {
    n = 16;
    ll arr[] = {0, 1, 0, 2, 1, 1, 3, 0, 4, 2, 5, 2, 2, 3, 1, 0, 2};
    for (int i = 1; i <= n; i++) {
        update(i, arr[i]);
    } 
    while (tree) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r; 
            cin >> l >> r;
            cout << rangeQuery(l, r) << '\n';
        }
        else if(op == 2) {
            int i;
            ll add;
            cin >> i >> add;
            update(i, add);
        }
        else break;
    }
}