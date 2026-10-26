// now i am doing the longest balanced substring 1
// i have given a string s consisting of lowecase english letters
// a substring of s is called balanced if all distinct characters in the substring appear the same number of times
// return the length of the longest balanced substring of s.
// approach we make hasmap of freq 26 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int freq[26];
    int longestBalanced(string s) {
        int cnt=1;
        int n=s.length();
        for(int i=0;i<n;i++){
            memset(freq,0,sizeof(freq));
            for(int j=i;j<n;j++){
                int unique=0;
                int maxfreq=0;
                int cntfreq=0;
                unique+=(f==1);
                if(f)
            }
        }
    }
};