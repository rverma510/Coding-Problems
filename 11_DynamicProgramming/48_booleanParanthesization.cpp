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

int memoizedParanthesis(string expression, int i, int j, bool isTrue, int ***mem) {
    if (i > j)
        return false;
    if (i == j) {
        if (isTrue)
            return expression[i] == 'T';
        else
            return expression[i] == 'F';
    }
    if (mem[i][j][isTrue] != -1) {
        // cout << "i = " << i << ", j = " << j << endl;
        return mem[i][j][isTrue];
    }
    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2) {
        int lt = memoizedParanthesis(expression, i, k - 1, true, mem);
        int lf = memoizedParanthesis(expression, i, k - 1, false, mem);
        int rt = memoizedParanthesis(expression, k + 1, j, true, mem);
        int rf = memoizedParanthesis(expression, k + 1, j, false, mem);
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
    return mem[i][j][isTrue] = ans;
}

int memoizedParanthesis(string exp, int i, int j, bool isTrue) {
    int ***mem = new int**[exp.size()];
    for (int i =0 ; i < exp.size(); i++) {
        mem[i] = new int*[exp.size()];
        for (int j = 0; j < exp.size(); j++) {
            mem[i][j] = new int[2];
            for (int k = 0; k < 2; k++) {
                mem[i][j][k] = -1;
            }
        }
    }
    int ans = memoizedParanthesis(exp, i, j, isTrue, mem);
    for (int i = 0; i < exp.size(); i++) {
        for (int j = 0; j < exp.size(); j++) {
            delete [] mem[i][j];
        }
        delete [] mem[i];
    }
    delete mem;
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
    cout << memoizedParanthesis(expression, 0, expression.size() - 1, true) << endl;
    return 0;
}