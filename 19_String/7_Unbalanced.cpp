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
const int maxn = 1e6 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void solve() {
    string s;
    getline(cin, s);
    map<int, vector<int>> mp;
    for (size_t i = 0; i < s.size(); i++) {
        mp[s[i] - 'a'].pb(i);
    }
    for (auto i: mp) {
        if (i.se.size() < 2) continue;
        for (size_t j = 0; j < i.se.size() - 1; j++) {
            for (size_t k = j + 1; k < i.se.size(); k++) {
                size_t len = i.se[k] - i.se[j] +  1;
                if (k - j + 1 > len / 2) {
                    cout << i.se[j] + 1 << " " << i.se[k] + 1 << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << " " << -1 << endl;
}

int main() {
    speed;
    // solve();
    string s;
    getline(cin, s);
    bool flag = true;
    for (size_t i = 0; i < s.size(); i++) {
        if (i < s.size() - 1 && s[i] == s[i + 1]) {
            cout << i + 1 << ' ' << i + 2 << endl;
            flag = false;
            break;
        }
        if (i < s.size() - 2 && s[i] == s[i + 2]) {
            cout << i + 1 << ' ' << i + 3 << endl;
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << -1 << ' ' << -1 << endl;
    }
    return 0;
}