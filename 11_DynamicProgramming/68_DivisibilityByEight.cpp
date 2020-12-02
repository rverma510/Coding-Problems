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

set<string> st;

string check(string s) {
    if (s.size() == 0 || st.find(s) != st.end()) return "";
    int n = 0;
    int i = s.size() >= 3 ? (s.size() - 3) : 0;
    // cout << i << ' ' << s << endl;
    while (i < s.size()) {
        n = n * 10 + (s[i] - '0');
        i++;
    }
    if (n % 8 == 0) {
        return s;
    }
    string ans = "";
    if (s.size() >= 1) {
        string r = s.substr(0, s.size() - 1);
        ans = check(r);
        if (ans == "") st.insert(r);
        else return ans;    
    }
    if (s.size() >= 2) {
        string r = s.substr(0, s.size() - 2) + s.substr(s.size() - 1, 1);
        ans = check(r);
        if (ans == "") st.insert(r);
        else return ans;
    }
    if (s.size() >= 3) {
        string r = s.substr(0, s.size() - 3) + s.substr(s.size() - 2, 2);
        ans = check(r);
        if (ans == "") st.insert(r);
        else return ans;
    }
    return ans;
}

void solve() {  
    string s;
    cin >> s;
    string res = check(s);
    if (res != "") {
        cout << "YES" << endl << res << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    speed;
    solve();
    return 0;
}