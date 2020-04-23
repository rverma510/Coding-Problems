#include <iostream>
using namespace std;
int returnFirstSetBit(int n){
    for(int i = 0; i < 32; i++){
        if(n & (1 << i))
			return (1 << i);
    }
    return 0;
}
int main() {
	int n;
	cin >> n;
	cout<< returnFirstSetBit(n) <<endl;
	return 0;
}