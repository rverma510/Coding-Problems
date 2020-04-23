#include <iostream>
using namespace std;
int clearAllBits(int n, int i){
    for(int j = 31; j >= i; j--){
        if(n & (1 << j)){
            n = n ^ (1 << j);
        }
    }
    return n;
}
int main() {
	int n, i;
	cin >> n >> i;
	cout<< clearAllBits(n, i) <<endl;
	return 0;
}

