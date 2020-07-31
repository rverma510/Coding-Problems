#include <bits/stdc++.h>
using namespace std;

int recursiveParanthesis(string expression, int i, int j, bool isTrue) {
    if (i > j)
        return false;
    if (i == j) {
        if (isTrue)
            return expression[i] == 'T';
        else
            return expression[i] == 'F';
    }
    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2) {
        int lt = recursiveParanthesis(expression, i, k - 1, true);
        int lf = recursiveParanthesis(expression, i, k - 1, false);
        int rt = recursiveParanthesis(expression, k + 1, j, true);
        int rf = recursiveParanthesis(expression, k + 1, j, false);
        if (expression[k] == '&') {
            if (isTrue)
                ans += lt * rt;
            else
                ans += lt * rf + lf * rt + lf * rf;
        }
        else if (expression[k] == '|') {
            if (isTrue)
                ans += lt * rt + lt * rf + lf * rt;
            else
                ans += lf * rf;
        }
        else {
            if (isTrue)
                ans += lt * rf + lf * rt;
            else
                ans += lf * rf + lt * rt; 
        }
    }
    return ans;
}

int main() {
    string symbols, operators;
    cin >> symbols >> operators;
    string expression = "";
    int i = 0;
    while (i < operators.size()) {
        expression += symbols[i];
        expression += operators[i];
        i++;
    }
    expression += symbols[i];
    cout << recursiveParanthesis(expression, 0, expression.size() - 1, true) << endl;
    return 0;
}