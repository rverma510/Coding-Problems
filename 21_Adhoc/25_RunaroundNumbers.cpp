#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int n, ans = INT_MAX;
bool visited[10];

bool check(int i) {
    vector<int> arr;
    while (i > 0) {
        arr.push_back(i % 10);
        i /= 10;
    }
    reverse(arr.begin(), arr.end());
    int m = arr.size();
    int cnt = {0};
    int start = 0;
    while (cnt < m) {
        cnt++;
        start = (start + arr[start] % m) % m;
        if (start == 0) break;
    }
    if (cnt >= m && start == 0) return true;
    else return false;
}

void generate(int num) {
    if (num > ans) return;
    if (num > n && check(num)) {
        ans = min(ans, num);
    }
    for (int i = 1; i <= 9; i++) {
        if (!visited[i]) {
            int tmp = num * 10 + i;
            visited[i] = true;
            generate(tmp);
            visited[i] = false;
        }
    }
}

int main() {
    speed;
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
    cin >> n;
    // auto t1 = chrono::high_resolution_clock().now();
    for (int i = 1; i <= 9; i++) {
        visited[i] = true;
        generate(i);
        visited[i] = false;
    } 
    // auto t2 = chrono::high_resolution_clock().now();
    // auto dur = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    // cout << "dur : " << dur << '\n';
    cout << ans << '\n';
    return 0;
}