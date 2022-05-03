//

#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += gas[i] - cost[i];
    }
    if (total < 0) return -1;
    int start = 0;
    int tank = 0;
    for (int i = 0; i < n; i++) {
        tank += gas[i] - cost[i];
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    return start;
}

int main() {
    int n;
    cin >> n;
    vector<int> gas(n), cost(n);
    for (int i = 0; i < n; i++) {
        cin >> gas[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    cout << canCompleteCircuit(gas, cost) << '\n';
    return 0;
}

/*

5
1 2 3 4 5
3 4 5 1 2

*/