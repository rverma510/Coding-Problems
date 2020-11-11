#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);
#define rf freopen("input.txt", "r", stdin);
#define wf freopen("output.txt", "w", stdout);
const int maxsize = 1e5 + 10;
int t, n;
int minX, maxX, range;
bool w[maxsize], b[maxsize]; 
int main() {
    speed;
    cin >> t;
    while (t--) {
        cin >> n >> minX >> maxX;
        range = maxX - minX + 1;
        for (int i = 0; i < n; i++) {
            int tmp_w, tmp_b;
            cin >> tmp_w >> tmp_b;
            w[i] = !(tmp_w % 2);
            b[i] = !(tmp_b % 2);
        }
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n -1) {
                w[i] = w[i] | w[i + 1];
                b[i] = b[i] | w[i + 1];
            }
            if (!b[i])
                cnt++;
        }
        if (cnt % 2) {
            if (w[0])
                cout << 0 << " " << range << "\n";
            else {
                if (range % 2 == 0) {
                    cout << range / 2 << " " << range / 2 << "\n";
                }
                else {
                    if (minX % 2 == 0)
                        cout << range / 2 << " " << range / 2 + 1<< "\n";
                    else
                        cout << range / 2 + 1 << " " << range / 2 << "\n";
                }
            }
        }
        else {
            if (w[0]) {
                cout << range << " " << 0 << "\n";
            }
            else {
                if (range % 2 == 0) {
                    cout << range / 2 << " " << range / 2 << "\n";
                }
                else {
                    if (minX % 2 == 0) 
                        cout << range / 2 + 1 << " " << range / 2 << "\n";
                    else
                        cout << range / 2 << " " << range / 2 + 1 << "\n";
                }
            }
        } 
    }
    return 0;
}
