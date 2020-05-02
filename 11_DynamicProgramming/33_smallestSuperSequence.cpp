/*
Given two strings S and T, find and return the length of their smallest super-sequence.
A shortest super sequence of two strings is defined as the shortest possible string containing both strings as subsequences.
Note that if the two strings do not have any common characters, then return the sum of lengths of the two strings.
Input Format:
Line 1 : A string
Line 2: Another string
Output Format:
Length of the smallest super-sequence of given two strings. 
Sample Input:
ab
ac
Sample Output:
3
Sample Output Explanation:
Their smallest super-sequence can be "abc" which has length=3.
*/
#include<bits/stdc++.h>
using namespace std;
int smallestSuperSequence(char str1[], int len1, char str2[], int len2) { 
    int **dp = new int*[len1 + 1];
    for(int i = 0; i <= len1; i++){
        dp[i] = new int[len2 + 1];
    }
    for(int i = 0; i <= len1; i++){
        for(int j = 0; j <= len2; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
        }
    }
    int ans = dp[len1][len2];
    for(int i = 0; i <= len1; i++){
        delete [] dp[i];
    }
    delete [] dp;
    return len1 + len2 - ans;
}
int main(){
    char str1[50], str2[50];
    cin>>str1;
    cin>>str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = smallestSuperSequence(str1, len1, str2, len2);
    cout<<min_len;
    return 0;
}
