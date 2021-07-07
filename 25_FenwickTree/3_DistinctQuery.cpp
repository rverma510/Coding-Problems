#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l, r, index;
};

const int maxn = 3e4+ 10;
const int sz = 1e6 + 10;

int n;
int BIT[maxn];
int arr[maxn];
int idx[sz];

void update(int i, int add) {
    while (i <= n) {
        BIT[i] += add;
        i += (i & (-i));
    }
}

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += BIT[i];
        i -= (i & (-i));
    }
    return s;
}

bool compare(const Query &a, const Query &b) {
    return a.r <= b.r;
}

int main() {
    memset(idx, -1, sizeof(idx));
	cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int q;
    cin >> q;
    Query query[q];
    for (int i = 0; i < q; i++) {
        cin >> query[i].l >> query[i].r;
        query[i].index = i;
    }
    sort(query, query + q, compare);
    // for (int i = 0; i < q; i++) {
    //     cout << query[i].l << query[i].r << query[i].index << '\n';
    // }
    int ans[q];
    int j = 1;
    for (int i = 0; i < q; i++) {
    	while (j <= n && j <= query[i].r) {
            if (idx[arr[j]] == -1) {
                idx[arr[j]] = j;
                update(j, 1);
            }
            else {
                update(idx[arr[j]], -1);
                idx[arr[j]] = j;
                update(j, 1);
            }
            j++;
        }
        ans[query[i].index] = sum(query[i].r) - sum(query[i].l - 1);
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
    
}
