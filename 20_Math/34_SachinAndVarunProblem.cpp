/*
Varun and you are talking about a movie that you have recently watched while Sachin is busy teaching 
Number Theory. Sadly, Sachin caught Varun talking to you and asked him to answer his question in 
order to save himself from punishment. The question says:
Given two weights of a and b units, in how many different ways you can achieve a weight of d units 
only the given weights? Any of the given weights can be used any number of times (including 0 
number of times). Since Varun is not able to answer the question, he asked you to help him 
otherwise he will get punished.

Note: Two ways are considered different if either the number of times a is used or number of 
times b is used is different in the two ways.

Input Format:
The first line of input consists of an integer 
T denoting the number of test cases.
Each test case consists of only one line containing three space separated integers a, b and d.

Output Format:
For each test case, print the answer in a separate line.

Constraints:
1 ≤T≤ 10^5

1 ≤ a < b ≤ 10^9

0≤d≤10^9

Sample Input 1
4
2 3 7
4 10 6
6 14 0
2 3 6

Sample Output 1
1
0
1
2
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct Triplet {
    ll x, y, gcd;
};

Triplet extendedEuclid(ll a, ll b) {
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

ll mmInverse(ll a, ll m) {
    int res = extendedEuclid(a, m).x;
    return (res % m + m) % m;
}

int main(){
	int t;
    cin >> t;
    while (t--) {
        ll a, b, d;
        cin >> a >> b >> d;
        if (d == 0) {
            cout << 1 << '\n';
            continue;
        }
        ll g = __gcd(a, b);
        if (d % g != 0) {
            cout << 0 << '\n';
            continue;
        }
        a /= g;
        b /= g;
        d /= g;
        ll smallest_y = ((d % a) * mmInverse(b, a)) % a;
        if (d < b * smallest_y) {
            cout << 0 << '\n';
            continue;
        }
        ll n = (d / b - smallest_y) / a;
        cout << (n + 1) << '\n';
    }
	return 0;
}