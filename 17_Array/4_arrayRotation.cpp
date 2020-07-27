#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int> &arr, int s, int e) {
    while (s < e) {
        int tmp = arr[s];
        arr[s] = arr[e];
        arr[e] = tmp;
        s++;
        e--;
    }
}
void leftRotate(vector<int> &arr, int d, int n) {
    if (d == 0)
        return;
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
}
void rightRotate(vector<int> &arr, int d, int n) {
    if (d == 0)
        return;
    reverse(arr, 0, n - d - 1);
    reverse(arr, n - d, n - 1);
    reverse(arr, 0, n - 1);

}
int main() {
    int n, d;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n ; i++)
        cin >> arr[i];
    cin >> d;
    d = d % n;
    rightRotate(arr, d, n);
    for (int i: arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}