#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int n;

// int IC{0}, VC{0}, XC{0}, LC{0}, CC{0}, DC{0}, MC{0}; 
// void count_roman(int i) {
//     int I{0}, V{0}, X{0}, L{0}, C{0}, D{0}, M{0};
//     for (;i >= 1000; M++, i -= 1000);
//     for (;i >= 500; D++, i -= 500);
//     for (;i >= 100; C++, i -= 100);
//     for (;i >= 50; L++, i -= 50);
//     for (;i >= 10; X++, i -= 10);
//     for (;i >= 5; V++, i -= 5);
//     for (;i >= 1; I++, i -= 1);
//     while (D > 0 && C / 4 > 0) {
//         D--;
//         C -= 3;
//         M++;
//     }
//     while (C >= 4) {
//         C -= 3;
//         D++;
//     }
//     while (L > 0 && X / 4 > 0) {
//         L--;
//         X -= 3;
//         C++;
//     }
//     while (X >= 4) {
//         X -= 3;
//         L++;
//     }
//     while (V > 0 && I / 4 > 0) {
//         V--;
//         I -= 3;
//         X++;
//     }
//     while (I >= 4) {
//         I -= 3;
//         V++;
//     }

//     IC += I;
//     VC += V;
//     XC += X;
//     LC += L;
//     CC += C;
//     DC += D;
//     MC += M;

// }
  

int ns[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
int m1[] = {6, 6, 5, 5, 4, 4, 3, 3, 2, 2, 1, 1, 0};
int m2[] = {-1, 4, -1, 4, -1, 2, -1, 2, -1, 0, -1, 0, -1};
int counts[7]{0};

void count_r(int num) {
    int cnts[] = {3, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 3};
    for (int i = 0; i < 13; i++) {
        while (cnts[i] > 0) {
            if (num - ns[i] >= 0) {
                num -= ns[i];
                counts[m1[i]]++;
                if (m2[i] != -1) counts[m2[i]]++;
                cnts[i]--;
            }
            else break;
        }
    }
}

string roman = "IVXLCDM";

int main() {
    speed;
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
    cin >> n;
    // for (int i = 1; i <= n; i++) {
    //     count_roman(i);
    // }
    // if (IC) cout << "I " << IC << '\n';
    // if (VC) cout << "V " << VC << '\n';
    // if (XC) cout << "X " << XC << '\n';
    // if (LC) cout << "L " << LC << '\n';
    // if (CC) cout << "C " << CC << '\n';
    // if (DC) cout << "D " << DC << '\n';
    // if (MC) cout << "M " << MC << '\n';
    
    for (int i = 1; i <= n; i++) {
        count_r(i);
    }
    for (int i = 0; i < 7; i++) {
        if (counts[i]) {
            cout << roman[i] << ' ' << counts[i] << '\n';
        }
    }
    return 0;

}