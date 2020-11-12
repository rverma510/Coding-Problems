#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);
#define rf freopen("in.txt", "r", stdin);
#define wf freopen("out.txt", "w", stdout);
using namespace std;
int t, n;
int arr[] = {100, 50, 10, 5, 2, 1};
int main() {
    speed;
    cin >> t;
    while (t--) {
        cin >> n;
        int i = 0, res = 0;
        while (n) {
            res += n / arr[i];
            n = n % arr[i];
            i++;
        }
        cout << res << "\n";
    }
    return 0;
}