#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int maxn = 250 * 250 * 2 + 10;

int n, m;
int arr[maxn];
bool bisquares[maxn];
int sz;

struct pr {
    int a, d;
};

bool comp(const pr &a, const pr &b) {
    return tie(a.d, a.a) < tie(b.d, b.a);
}

void solve() {
    bool found = true;
    vector<pr> res;
    int m_max = m * m * 2 + 1;
    for (int i = 0; i < sz - n + 1; i++) {
        for (int j = i + 1; j < sz - n + 2; j++) {
            int d = arr[j] - arr[i];
            int dcount = 2;
            int curr = arr[j] + d;
            while (curr < m_max && bisquares[curr] && dcount != n) {
                curr += d;
                dcount++;
            }
            if (dcount == n) res.push_back({arr[i], d});
        }
    }
    if (res.empty()) {
        cout << "NONE\n";
        return;
    }
    sort(res.begin(), res.end(), comp);
    for (auto i: res) {
        cout << i.a << ' ' << i.d << '\n';
    }
}

int main() {
    speed;
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            bisquares[i * i + j * j] = 1;
        }
    }
    for (int i = 0; i < maxn; i++) {
        if (bisquares[i]) arr[sz++] = i;
    }
    solve();
    return 0;
}