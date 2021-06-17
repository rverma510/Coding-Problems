#include <bits/stdc++.h>
using namespace std;
vector<string> paran;

void helper(int l, int r, string p) {
    if (l == 0 && r == 0) {
        paran.push_back(p);
        return;
    }
    
    if (l > 0) {
        helper(l - 1, r, p + "(");
    }
        
    if (r > 0 && l < r) {
        helper(l, r - 1, p + ")");   
    }
}

void generateParenthesis(int n) {
    paran.clear();
    helper(n, n, "");
}

int main() {
    int n = 4;
    generateParenthesis(n);
    for (int i = 0; i < paran.size(); i++) {
        cout << paran[i] << '\n'; 
    }
    return 0;
}