#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void solve(vector<int> &arr) {
    stack<int> st;
    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && st.top() >= arr[i])
            st.pop();
        if (!st.empty()) 
            cout << st.top() << ", ";
        else
            cout << "_, ";
        st.push(arr[i]);
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    solve(v);
    return 0;
}