#include <bits/stdc++.h>
using namespace std;

int recursiveLCS(string x, int m, string y, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (x[m - 1] == y[n - 1])
        return 1 + recursiveLCS(x, m - 1, y, n - 1);
    else
        return max(recursiveLCS(x, m - 1, y, n), recursiveLCS(x, m, y, n - 1));
}

int main() {
    string x, y;
    cin >> x >> y;
    cout << recursiveLCS(x, x.size(), y, y.size()) << endl;
    return 0;
}