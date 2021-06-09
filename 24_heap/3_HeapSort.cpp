#include <bits/stdc++.h>
using namespace std;

// max_heapify for sorting in ascending order
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

void heap_sort(int* arr, int n) {
    build_heap(arr, n);
    for (int i = n; i >= 2; i--) {
        swap(arr[1], arr[n]);
        n--;
        max_heapify(arr, 1, n);
    }
}

int main() {
    int arr[] = {INT_MIN, 4, 25, 2, 56, 1, 6, 3, 5, 12, 6};
    int n = sizeof(arr) / sizeof(int); n--;
    cout << "Before heap sort\n";
    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    heap_sort(arr, n);
    cout << "\nAfter heap sort\n";
    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    return 0;
}