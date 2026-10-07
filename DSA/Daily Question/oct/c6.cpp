// right now we are doing premuatiaon in String
// i have given two strings s1 and s2 return ture if s2 conatins a permuatation of s1, or false otherwise
// in other word return true if one of s1's permutations is the substring of s2.
// we used slidiond window technique to solve this problem

#include <bits/stdc++.h>
using namespace std;
class Solution{
 public:
 
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n>m) return false;
        vector<int> count1(26,0);
        vector<int> count2(26,0);
        for(int i=0;i<n;i++){
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
        }
        if(count1==count2) return true;
        for(int i=n;i<m;i++){
            count2[s2[i]-'a']++;
            count2[s2[i-n]-'a']--;
            if(count1==count2) return true;
        }
        return false;
    }

};