#include <bits/stdc++.h>
using namespace std;
struct Coders {
    int x, y, index;
};

void update(int y, int *BIT) {
    while (y <= 100000) {
        BIT[y]++;
        y += (y & (-y));
    }
}

int query(int y, int *BIT) {
    int count = 0;
    while (y > 0) {
        count += BIT[y];
        y -= (y & (-y));
    }
    return count;
}

bool compare(const Coders &a, const Coders &b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

int main() {
    int n;
    cin >> n;
    Coders *coders = new Coders[n];
    for (int i = 0; i < n; i++) {
        cin >> coders[i].x >> coders[i].y;
        coders[i].index = i;
    }
    sort(coders, coders + n , compare);
    
    int *BIT = new int[100001];
    int *ans = new int[n];
    for (int i = 0; i < n;) {
        int endIndex = i;
        while (endIndex < n && 
                coders[i].x == coders[endIndex].x && 
                coders[i].y == coders[endIndex].y) endIndex++;

        for (int j = i; j < endIndex; j++) {
            ans[coders[j].index] = query(coders[j].y, BIT);
        }

        for (int j = i; j < endIndex; j++) {
            update(coders[j].y, BIT);
        }

        i = endIndex;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
    
    delete [] coders;
    delete [] BIT;
    delete [] ans;

    return 0;
}
