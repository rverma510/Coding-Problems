// https://leetcode.com/problems/evaluate-reverse-polish-notation

#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    int n = tokens.size();
    for (int i = 0; i < n; i++) {
        if (tokens[i] == "+") {
            int val1 = st.top(); st.pop();
            int val2 = st.top(); st.pop();
            st.push(val2 + val1);
        }
        else if (tokens[i] == "-") {
            int val1 = st.top(); st.pop();
            int val2 = st.top(); st.pop();
            st.push(val2 - val1);
        }
        else if (tokens[i] == "*") {
            int val1 = st.top(); st.pop();
            int val2 = st.top(); st.pop();
            st.push(val2 * val1);
        }
        else if (tokens[i] == "/") {
            int val1 = st.top(); st.pop();
            int val2 = st.top(); st.pop();
            st.push(val2 / val1);
        }
        else {
            st.push(stoi(tokens[i]));
        }
    }
    return st.top();
}

int main() {
    int n; cin >> n;
    vector<string> tokens(n);
    for (int i = 0; i < n; i++) {
        cin >> tokens[i];
    }
    cout << evalRPN(tokens) << '\n';
    return 0;
}

/*

5
2 1 + 3 *

*/