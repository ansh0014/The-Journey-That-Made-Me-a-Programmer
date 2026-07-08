// now we are doing the last substring in Lexicographical order
// given a string s, return the last ssubstring of s in lexicographical order
// input : s = "abab" output: "bab" 
// input : s = "leetcode" output: "tcode"
// approach we will use two pointer approach to find the last substring in lexicographical order


#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
       string lastSubstring(string s) {
        
        int n = s.size();
        int i = 0, j = 1, k = 0;
        while (j + k < n) {
            if (s[i + k] == s[j + k]) {
                k++;
            } else if (s[i + k] < s[j + k]) {
                i = max(i + k + 1, j);
                j = i + 1;
                k = 0;
            } else {
                j = j + k + 1;
                k = 0;
            }
        }
        return s.substr(i);
        
   }
};
