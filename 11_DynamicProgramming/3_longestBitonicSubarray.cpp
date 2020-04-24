#include<bits/stdc++.h>
using namespace std;
int longestBitonicSubarray(int *input, int n){
    int *output1 = new int[n];
    int *output2 = new int[n];
    for(int i = 0; i < n; i++){
        output1[i] = 1;
        output2[i] = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(input[i] > input[j]){
                output1[i] = max(output1[i], output1[j] + 1);
            }
        }
    }
    for(int i = n - 2; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            if(input[i] > input[j]){
                output2[i] = max(output2[i], output2[j] + 1);
            }
        }
    }
    int best = 0;
    for(int i = 0; i < n; i++){
        if(best < output1[i] + output2[i])
            best = output1[i] + output2[i];
    }
    return best - 1;
}
int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubarray(input, n);
  return 0;
}
