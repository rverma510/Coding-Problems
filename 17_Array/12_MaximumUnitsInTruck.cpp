#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int> &a, const vector<int> &b) {
    return a[1] >= b[1];
}

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), compare);
    int ans = 0;
    for (int i = 0; i < boxTypes.size(); i++) {
        if (boxTypes[i][0] <= truckSize) {
            ans += boxTypes[i][0] * boxTypes[i][1];
            truckSize -= boxTypes[i][0];
        }
        else {
            ans += truckSize * boxTypes[i][1];
            break;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> boxTypes = {{5, 10}, {2, 5}, {4, 7}, {3, 9}};
    int truckSize = 10;
    cout << maximumUnits(boxTypes, truckSize) << '\n';
    return 0;
}