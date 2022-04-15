

#include <bits/stdc++.h>
using namespace std;

string getSubPath(string path, int i, int j) {
    string s = "";
    for (int k = i; k <= j; k++) {
        s += path[k];
    }
    reverse(s.begin(), s.end());
    return s;
}
string simplifyPath(string path) {
    if (path == "/") return path;
    int i = 0, j = 1;
    int n = path.length();
    stack<string> st;
    while (j < n) {
        if (path[j] == '/' && j == i + 1) {
            i = j;
        }
        else if (path[j] == '/') {
            string s = getSubPath(path, i + 1, j - 1);
            if (s != "." && s != "..") {
                st.push(s);
            }
            else if (s == ".." && !st.empty()) {
                st.pop();
            }
            i = j;
        }   
        j++;
    }
    if (j != i + 1) {
        string s = getSubPath(path, i + 1, j - 1);
        if (s != "." && s != "..") {
            st.push(s);
        }
        else if (s == ".." && !st.empty()) {
            st.pop();
        }
    }
    string res = "";
    if (st.empty()) {
        res = "/";
    }
    while (!st.empty()) {
        res += st.top() + "/";
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string path;
    cin >> path;
    cout << simplifyPath(path) << '\n';
    return 0;
}