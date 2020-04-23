#include<bits/stdc++.h>
using namespace std;
int numCodes(int *n, int size){
    if(size == 0 || size == 1){
        return 1;
    }
    int output = numCodes(n, size - 1);
    if(n[size - 2] * 2 + n[size - 1] <= 26)
        output += numCodes(n, size - 2);
    return output;
}
int numCodes2(int *n, int size, int * arr){
    if(size == 0 || size == 1){
        return 1;
    }
    if(arr[size] > 0)
        return arr[size];
    int output = numCodes(n, size - 1);
    if(n[size - 2] * 2 + n[size - 1] <= 26)
        output += numCodes(n, size - 2);
    arr[size] = output;
    return output;
}
int numCodesItr(int *input, int size){{
    int *output = new int[size + 1];
    output[0] = 1;
    output[1] = 1;
    for(int i = 2; i <= size; i++){
        output[i] = output[i - 1];
        if(input[i - 2] * 10 + input[i - 1] <= 26)
            output[i] += output[i - 2];
    } 
    int ans = output[size];
    delete [] output;
    return ans;
}}
int main(){
    int size;
    cin>>size;
    int * input = new int[size];
    for(int i = 0; i < size; i++)
        cin>>input[i];
    cout<<numCodesItr(input, size)<<endl;
    return 0;
}