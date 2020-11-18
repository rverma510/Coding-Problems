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
const int maxn = 1e2 + 10;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n, l;
char ch;
string arr[maxn];

bool compare(const string &a, const string &b) {
    int i = 0;
    while (i < l && (a[i] == b[i])) i++;
    if (i == l || a[i] > b[i]) {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    speed;
    cin >> n >> l; cin.get(ch);
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }
    // for (int i = 1; i < n; i++) {
    //     int j = i - 1;
    //     string tmp = arr[i];
    //     while (j >= 0 && compare(tmp, arr[j])) {
    //         arr[j + 1] = arr[j];
    //         j--;
    //     }
    //     arr[j + 1] = tmp;
    // }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {cout << arr[i];}
    cout << endl;
    return 0;
}