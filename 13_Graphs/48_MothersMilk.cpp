/*

Farmer John has three milking buckets of capacity A, B, and C liters. Each of the numbers A, B, and C is an integer from 1 through 20, inclusive. Initially, buckets A and B are empty while bucket C is full of milk. Sometimes, FJ pours milk from one bucket to another until the second bucket is filled or the first bucket is empty. Once begun, a pour must be completed, of course. Being thrifty, no milk may be tossed out.

Write a program to help FJ determine what amounts of milk he can leave in bucket C when he begins with three buckets as above, pours milk among the buckets for a while, and then notes that bucket A is empty.

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int maxn = 20;

struct State {
    int a[3];
    State(int x, int y, int z) {
        a[0] = x;
        a[1] = y;
        a[2] = z;
    }
};

int cap[3];
bool visit[maxn + 1][maxn + 1][maxn + 1];
bool aval[maxn + 1];


State pour(State s, int i, int j) {
    int amt = s.a[i];
    if (s.a[j] + amt > cap[j]) amt = cap[j] - s.a[j];
    s.a[i] -= amt;
    s.a[j] += amt;    
    return s;
}

void search(State s) {
    if (visit[s.a[0]][s.a[1]][s.a[2]]) return;
    visit[s.a[0]][s.a[1]][s.a[2]] = 1;
    if (s.a[0] == 0) aval[s.a[2]] = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            search(pour(s, i, j));
        }
    }
}

int main() {
    speed;
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    cin >> cap[0] >> cap[1] >> cap[2];
    search(State(0, 0, cap[2]));
    for (int i = 0; i < cap[2]; i++) {
        if (aval[i]) cout << i << ' ';
    }
    cout << cap[2] << endl;
    return 0;
}