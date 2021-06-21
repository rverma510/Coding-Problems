#include <bits/stdc++.h>
using namespace std;

struct Triplet {
    int x, y, gcd;
};

Triplet extendedEuclid(int a, int b) {

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
    int a = 2;
    int b = 3;
    Triplet res =  extendedEuclid(a, b);
    cout << "X and y of ax + by = gcd(a, b) : " << res.x << ' ' << res.y << ' ' << res.gcd << '\n';
    return 0;
}