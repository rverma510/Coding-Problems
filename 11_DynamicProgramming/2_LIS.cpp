#include<bits/stdc++.h>
using namespace std;
int LIS(int *input, int n){
    int *output = new int[n];
    for(int i = 0; i < n; i++)
        output[i] = 1;
    int best = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(input[j] < input[i]){
                output[i] = max(output[i], output[j]+1);
            }
        }
        if(best < output[i])
            best = output[i];
    }
    delete [] output;
    return best;
}
int main(){
    int n;
    cin>>n;
    int *input = new int[n];
    for(int i = 0; i < n; i++)
        cin>>input[i];
    cout<<LIS(input, n)<<endl;
    delete [] input;
    return 0;
}