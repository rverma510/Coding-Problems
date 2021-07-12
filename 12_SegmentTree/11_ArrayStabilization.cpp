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

int t, n;
void buildTree(int *tree, int *arr, int start, int end, int treeNode) {
    if (start == end) {
        tree[treeNode] = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    buildTree(tree, arr, start, mid, 2 * treeNode);
    buildTree(tree, arr, mid + 1, end, 2 * treeNode + 1);
    tree[treeNode] = __gcd(tree[2 * treeNode], tree[2 * treeNode + 1]);
}

int query(int *tree, int start, int end, int l, int r, int treeNode) {
    if (start > r || end < l) return 0;
    if (start >= l && end <= r) return tree[treeNode];
    int mid = start + (end - start) / 2;
    int g1 = query(tree, start, mid, l, r, 2 * treeNode);
    int g2 = query(tree, mid + 1, end, l, r, 2 * treeNode + 1);
    return __gcd(g1, g2);
}

bool check(int *tree, int n, int mid) {
    set<int> se;
    for (int i = 0; i < n; i++) {
        se.insert(query(tree, 0, 2 * n - 1, i, i + mid - 1, 1));
        if (se.size() != 1) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    int arr[2 * n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[n + i] = arr[i];
    }
    int tree[6 * n];
    buildTree(tree, arr, 0, 2 * n - 1, 1);
    
    int l = 1, r = n;
    int ans = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(tree, n, mid)) {
            ans = mid - 1;
            r = mid - 1;
        } 
        else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    speed;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}