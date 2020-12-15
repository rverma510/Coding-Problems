#include <bits/stdc++.h>
using namespace std;

#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define rf freopen("in.txt", "r", stdin);
#define wf freopen("out.txt", "w", stdout);

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define mem(a, b) memset(a, b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7;

const double pi = acos(-1.0);
const int maxn = 3;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

string s;

void solve() {
    getline(cin, s);
    s+="-";
    string r = "";
    int cnt = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) cnt++;
        else {
            cnt = cnt <= 2 ? cnt : 2;
            r += s[i - 1] + to_string(cnt);
            cnt = 1;
        } 
    }
    for (int i = 1; i < r.size(); i += 2) {
        if (i + 2 < r.size() && r[i] == r[i + 2] && r[i] == '2') r[i + 2] = '1';
    }
    for (int i = 0; i < r.size(); i += 2) {
        int sz = r[i + 1] - '0';
        while (sz--) cout << r[i];
    }
}

int main() {
    speed;
    solve();
    return 0;
}