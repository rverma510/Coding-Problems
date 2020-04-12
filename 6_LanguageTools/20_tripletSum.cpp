#include<bits/stdc++.h>
using namespace std;
void FindTriplet(int arr[], int size, int x) {
    sort(arr, arr + size);
    for(int i = 0; i < size - 2; i++){
        int s = i + 1;
        int e = size - 1;
        int val = x - arr[i];
        while(s < e){
            if(arr[s] + arr[e] < val)
                s++;
            else if(arr[s] + arr[e] > val)
                e--;
            else{
                int countS = 0, countE = 0;
                for(int j = s; j <= e; j++)
                    if(arr[s] == arr[j])
                        countS++;
                    else
                        break;
                for(int j = e; j >= s; j--)
                    if(arr[e] == arr[j])
                        countE++;
                    else
                        break;            
                int comb = countS * countE;
                if(arr[s] == arr[e])
                    comb = ((e - s + 1) * (e - s)) / 2;
                for(int j = 0; j < comb; j++)
                    cout<<arr[i]<<" "<<arr[s]<<" "<<arr[e]<<endl;
                s += countS;
                e -= countE;
            }
        }
    }
}
int main(){
    int n, x;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cin>>x;
    FindTriplet(arr, n, x);
    return 0;
}