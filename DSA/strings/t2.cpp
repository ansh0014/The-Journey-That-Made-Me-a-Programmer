// now i am doing the longest happy prefix
// i have to match the longest prefix which is also suffix and then i have to return the longest prefix which is also suffix
// for that i have to use kmp algorithm to find the longest prefix which is also suffix and then i have to return the longest prefix which is also suffix
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
            }
            else{
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
    string longestPrefix(string s){
        vector<int> lps=buildLPS(s);
        int longestPrefixSuffix=lps[s.size()-1];
        return s.substr(0,longestPrefixSuffix);
        
    }
};