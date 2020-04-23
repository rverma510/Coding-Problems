#include <iostream>
using namespace std;
int turnOffFirstSetBit(int n){
    for(int i = 0; i < 32; i++){
        if(n & (1 << i)){
            n -= (1 << i);
            break;
        }
    }
    return n;
}
int main() {
	int n;
	cin >> n;
	cout<< turnOffFirstSetBit(n) <<endl;
	return 0;
}

