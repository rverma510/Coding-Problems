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
    const int maxn = 3e2 + 10;
    const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    void solve() {
        ll n, x1, x2, y1, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ll a, b, c;
            cin >> a >> b >> c;
            ll tmp1 = a * x1 + b * y1 + c;
            ll tmp2 = a * x2 + b * y2 + c;
            if ((tmp1 > 0 && tmp2 < 0) || (tmp1 < 0 && tmp2 > 0)) ans++;
        }
        cout << ans << endl;
    }

    int main() {
        speed;
        solve();
        return 0;
    }