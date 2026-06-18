// now i am doing the repeated substring pattern
// i have to kmp algorithm to find the longest prefix which is also suffix and then i have to check if the length of the string is divisible by the length of the longest prefix which is also suffix and if it is divisible then i will return true otherwise i will return false
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> buildLPS(string pattern){
        int n=pattern.size();
        vector<int> lps(n,0);
        int len=0;
        int i=1;
        while(i<n){
            if(pattern[i]==pattern[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len!=0){
                    len=lps[len-1];
                }else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
    }
    bool repeatedSubstringPattern(string s){
        vector<int> lps=buildLPS(s);
        int n=s.size();
        int longestPrefixSuffix=lps[n-1];
        if(longestPrefixSuffix>0 && n%(n-longestPrefixSuffix)==0){
            return true;
        }
        return false;
    }
};