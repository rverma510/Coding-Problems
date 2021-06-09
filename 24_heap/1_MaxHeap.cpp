#include <bits/stdc++.h>
using namespace std;

void max_heapify(int* arr, int i, int n) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[left] > arr[largest]) largest = left;
    if (right <= n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        max_heapify(arr, largest, n);
    }
}   

void build_heap(int* arr, int n) {
    for (int i = n / 2; i >= 1; i--) {
        max_heapify(arr, i, n);
    }
}

int main() {
    int arr[] = {INT_MIN, 1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    cout << "Before build heap\n";
    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    build_heap(arr, n);
    cout << "\nAfter build heap\n";
    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    return 0;
}