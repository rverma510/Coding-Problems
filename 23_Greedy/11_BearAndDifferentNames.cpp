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
const int maxn = 5e1 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n, k;
bool arr[maxn];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string alphabets[2] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ", "abcdefghijklmnopqrstuvwxyz"}; 
set<string> st;

string generate_random_string() {
    int sz = rng() % 10 + 1;
    int i = rng() % 26;
    string s = "";
    s += alphabets[0][i];
    while (sz > 1) {
        i = rng() % 26;
        s += alphabets[1][i];
        sz--;
    }
    return s;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n - k + 1; i++) {
        string tmp; cin >> tmp;
        if (tmp == "YES") arr[i] = true;
        else arr[i] = false;
    }
    vector<string> res;
    for (int i = 0; i < k; i++) {
        string s = generate_random_string();
        if (st.find(s) != st.end()) {
            i--;
            continue;
        } 
        res.pb(s);
        st.insert(s);
    }
    if (!arr[0]) {
        res[1] = res[0];
    }
    for (int i = 1; i < n - k + 1; i++) {
        if (arr[i]) {
            string s = generate_random_string();
            if (st.find(s) != st.end()) {
                i--;
                continue;
            } 
            res.pb(s);
            st.insert(s);
        }
        else {
            res.pb(res[i]);
        }
    }
    for (auto i: res) cout << i << ' ';
    cout << endl;
}

int main() {
    speed;
    solve();
    return 0;
}