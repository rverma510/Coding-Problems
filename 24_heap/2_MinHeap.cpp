#include <bits/stdc++.h>
using namespace std;

void min_heapify(int* arr, int i, int n) {
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

void build_heap(int* arr, int n) {
    for (int i = n / 2; i >= 1; i--) {
        min_heapify(arr, i, n);
    }
}

int main() {
    int arr[] = {INT_MAX, 7, 6, 5, 4, 3, 2, 1};
    int n = 7;
    cout << "Before build heap\n";
    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    build_heap(arr, n);
    cout << "\nAfter build heap\n";
    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    return 0;
}