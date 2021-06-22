#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int t;
    cin >> t;
    while (t--) {
    	int a;
        string s;
        cin >> a >> s;
        if (a == 0) {
            cout << s << '\n';
            continue;
        }
        int b = 0;
        for (int i = 0; i < s.size(); i++) {
            b = (b * 10 + s[i] - '0') % a;
        }
        cout << gcd(a, b) << '\n';    
    }
    
	return 0;
}