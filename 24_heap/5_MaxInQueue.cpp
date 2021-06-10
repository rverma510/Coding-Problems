#include <bits/stdc++.h>
using namespace std;

void max_heapify(vector<int> &arr, int i, int n) {
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

void build_heap(vector<int> &arr, int n) {
	for (int i = n / 2; i >= 1; i--) {
		max_heapify(arr, i, n);
	}
}

void insert(vector<int> &arr, int &n, int val) {
	arr.push_back(val);
	n++;
	int i = n;
	while (i > 1 && arr[i / 2] < arr[i]) {
		swap(arr[i], arr[i / 2]);
		i /= 2;
	}
}

int main() {
	int n, m;
	cin >> n;
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i];
	build_heap(arr, n);
	cin >> m;
	while (m--) {
		int op, val;
		cin >> op;
		if (op == 1) {
			cin >> val;	
			insert(arr, n, val);
		}
		else if (op == 2) {
			cout << arr[1] << '\n';
		}
	}
}