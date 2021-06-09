#include <bits/stdc++.h>
using namespace std;

void min_heapify(vector<int> &arr, int i, int n) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[left] < arr[smallest]) smallest = left;
    if (right <= n && arr[right] < arr[smallest]) smallest = right;
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        min_heapify(arr, smallest, n);
    }
}

void build_heap(vector<int> &arr, int n) {
    for (int i = n / 2; i >= 1; i--) {
        min_heapify(arr, i, n);
    }
}

int minimum(vector<int> &arr, int n) {
    if (n <= 0) {
        cout << "Priority Queue empty\n";
        return INT_MAX;
    } 
    return arr[1];
} 

int extract_min(vector<int> &arr, int &n) {
    if (n <= 0) {
        cout << "Priority Queue empty\n";
        return INT_MAX;
    } 
    int min = arr[1];
    arr[1] = arr[n];
    n--;
    min_heapify(arr, 1, n);
    return min;
}

void decrease_val(vector<int> &arr, int i, int val) {
    if (arr[i] < val) {
        cout << "New value is more than current, can't be inserted\n";
        return;
    }
    arr[i] = val;
    while (i > 1 && arr[i / 2] > arr[i]) {
        swap(arr[i], arr[i / 2]);
        i /= 2;
    }
}

void insert(vector<int>& arr, int &n, int val) {
    arr.push_back(INT_MAX);
    n++;
    decrease_val(arr, n, val);
}

void print_arr(vector<int> &arr, int n) {
    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    cout << '\n';
}

int main() {
    vector<int> arr = {INT_MIN, 4, 1, 5, 2, 5, 6, 7, 2, 4, 1};
    int n = (int) arr.size(); n--;
    build_heap(arr, n);
    print_arr(arr, n);
    cout << "Minimum value : " << minimum(arr, n) << '\n';
    cout << "Extracting min value : " << extract_min(arr, n) << '\n';
    print_arr(arr, n);
    cout << "Inserting value 3\n";
    insert(arr, n, 3);
    print_arr(arr, n);
    return 0;
}