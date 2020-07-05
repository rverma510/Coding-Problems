// https://leetcode.com/problems/longest-substring-without-repeating-characters/
/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        set<char> st;
        int i, start = 0, size = 1;
        st.insert(s[0]);
        for (i = 1; i < s.size(); i++) {
            if (st.find(s[i]) != st.end()) {
                size = max(size, i - start);
                while (start < i) {
                    if (s[start] == s[i]){
                        break;
                    }
                    st.erase(s[start]);
                    start++;
                }
                start++;
            }
            st.insert(s[i]);
        }
        size = max(size, i - start);
        return size;
    }
};