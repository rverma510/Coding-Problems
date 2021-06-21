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

int mmInverse(int a, int m) {
    Triplet res = extendedEuclid(a, m);
    return res.x;
}

int main() {
    int a = 5;
    int m = 1e9 + 7;
    int res =  mmInverse(a, m);
    cout << "Multiplicative Modulo Inverse of a : " << res <<  '\n';
    return 0;
}