int Solution::fibsum(int A) {
    vector<int> fib{1, 1};
    while (fib.back() < A) {
        int x = fib[fib.size() - 1] + fib[fib.size() - 2];
        fib.push_back(x);
    }
    int ans = 0;
    while (A > 0) {
        if (binary_search(fib.begin(), fib.end(), A)) {
            A = 0;
        }
        else {
            auto it = lower_bound(fib.begin(), fib.end(), A);
            it--;
            int id = it - fib.begin();
            A -= fib[id];
        }
        ans++;
    }
    return ans;
}
