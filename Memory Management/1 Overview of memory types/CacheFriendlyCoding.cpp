#include <chrono>
#include <iostream>
using namespace std;
int main() {
    const int size = 4000;
    static int x[size][size];
    
    auto t1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            x[i][j] = i + j;
            // x[j][i] = i + j;
        }
    }
    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "Execution time : " << duration << " microseconds" << endl;
    return 0;

}