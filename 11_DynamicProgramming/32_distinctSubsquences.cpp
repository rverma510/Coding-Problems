/*
Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which 
is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters.
For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.

Input
First line of input contains an integer T which is equal to the number of test cases. You are required to process all test cases. Each of next T lines contains a 
string s.

Output
Output consists of T lines. Ith line in the output corresponds to the number of distinct subsequences of ith input string. Since, this number could be very large,
you need to output ans%1000000007 where ans is the number of distinct subsequences. 

Constraints and Limits
T ≤ 100, length(S) ≤ 100000

All input strings shall contain only uppercase letters.

Sample Input
3
AAA
ABCDEFG
CODECRAFT

Sample Output
4
128
496
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MAX 100005
long long int sum[MAX], dp[MAX];
void solve(string str){
    vector<int> last(26, -1);
    int n = str.length();
    dp[0] = 1;
    sum[0] = 1;
    dp[1] = 1;
    sum[1] = 2;
    last[str[0] - 65] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = sum[i - 1];
        if(last[str[i - 1] - 65] != -1)
            dp[i] -= sum[last[str[i - 1] - 65] - 1];
        sum[i] = (sum[i - 1] + dp[i]) % mod;
        if(sum[i] < 0)
            sum[i] += mod;
        last[str[i - 1] - 65] = i;
    }
    cout<<sum[n]<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        solve(str);
    }
    return 0;
}