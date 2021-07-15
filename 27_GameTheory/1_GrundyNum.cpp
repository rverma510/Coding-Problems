#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int grundy[maxn];

int MEX(int a, int b, int c) {
    vector<int> arr{a, b, c};
    sort(arr.begin(), arr.end());
    if (arr[0] != 0) return 0;
    if (arr[1] - arr[0] > 1) return arr[0] + 1;
    if (arr[2] - arr[1] > 1) return arr[1] + 1;
    return arr[2] + 1;
}

int findGrundy(int n) {
    if (n == 0) return 0;
    if (grundy[n] != -1) return grundy[n];
    int a = findGrundy(n / 2);
    int b = findGrundy(n / 3);
    int c = findGrundy(n / 6);
    grundy[n] = MEX(a, b, c);
    return grundy[n];
}

int main() {
	memset(grundy, -1, sizeof(grundy));
    int n;
    cin >> n;
    cout << findGrundy(n) << '\n';
}