// now i am doing the wildcard matching
// i have given the input string s and a pattern (p),implement wildcard pattern matching with support for'?'and '*'where:
// '?' matchers any single character
// '*' matches any sequence of character  (including the empty sequence)
// the matching should cover the entire input string (not partial)
// lets start to think the approach that we used in this question 
// let writ the pseudo code for this problem
// we used the loop then used the '?' and '*' to match the string with the pattern. we will use two pointers, one for the string and one for the pattern. we will iterate through the string and pattern using these pointers. if the current character in the pattern is equal to the current character in the string or if it is a '?', we will move both pointers forward. if the current character in the pattern is a '*', we will store the position of the '*' and move the pattern pointer forward. if there is a mismatch, we will check if there was a previous '*' in the pattern. if there was, we will move the string pointer forward and reset the pattern pointer to the position after the '*'. if there was no previous '*', we will return false as there is no match. finally, we will check if there are any remaining characters in the pattern that are not matched with '*' and return true if all characters are matched.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
bool isMatch(string s, string b){
    
    int i=0,j=0,star=-1,match=0;
    while(i<s.size()){
        if(j<b.size() && (s[i]==b[j] || b[j]=='?')){
            i++;
            j++;
        }else if(j<b.size() && b[j]=='*'){
            star=j;
            match=i;
            j++;
        }else if(star!=-1){
            j=star+1;
            match++;
            i=match;
        }else{
            return false;
        }
    }
    while(j<b.size() && b[j]=='*'){
        j++;
    }
    return j==b.size();
}
};