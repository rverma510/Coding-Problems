#include <bits/stdc++.h>
using namespace std;

struct Triplet {
    int x, y, gcd;
};

Triplet extendedEuclid(int a, int b) {
    if (a < b) return extendedEuclid(b, a);

    if (b == 0) {
        Triplet res;
        res.gcd = a;
        res.x = 1;
        res.y = 0;
        return res;
    } 

    Triplet ans = extendedEuclid(b, a % b);
    Triplet res;
    res.gcd = ans.gcd;
    res.x = ans.y;
    res.y = (ans.x - (a / b) * ans.y);
    return res;
}

int main() {
    int a = 42;
    int b = 18;
    Triplet res =  extendedEuclid(a, b);
    cout << "X and y of ax + by = gcd(a, b) : " << res.x << ' ' << res.y << '\n';
    return 0;
}