#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) return n;
    int curr = nums[0], count = 1;
    int j = 1, i = 1;
    bool first = true;
    while (j < n) {
        if (curr == nums[j]) {
            count++;
        }
        else {
            curr = nums[j];
            count = 1;
        }
        if (count <= 2) {
            nums[i] = nums[j];
            i++;
        }
        j++;
    }
    return i;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    n = removeDuplicates(nums);
    for (int i = 0; i < n; i++) {
        cout << nums[i];
    }
    cout << '\n';
    return 0;
}