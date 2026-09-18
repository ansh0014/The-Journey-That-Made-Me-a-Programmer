// now i am doing the shortest common  supersequence 
// i have given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequence. if there are multiple valid strings return any of them.
// a string s is subsequence fo string t if deleting some number characters from t (possibly 0) results in the string s.
// this shortest common supersequence so i have think state
// state is the indexes of str1 or str2 
// now what is transition= if str1[i]==str2[j] then i can take this character and move both indexes forward
// if str1[i]!=str2[j] then i can take either str1[i] or str2[j] and move the index of that string forward
// if i take str1[i] then i will move index of str1 forward and keep index of str2 same and vice versa
// first we find the lcs of str1 and str2 
// then we add remaning characters of str1 and str2 to the lca to get the shortest common supersequence
#include <bits/stdc++.h>
using namespace std;
class Solution {
    int dp[1001][1001];
    public:
    int lcs(int i,int j,string& str1,string& str2){
        if(i==str1.size() || j==str2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(str1[i]==str2[j]){
            return dp[i][j]=1+lcs(i+1,j+1,str1,str2);
        }
        else{
            return dp[i][j]=max(lcs(i+1,j,str1,str2),lcs(i,j+1,str1,str2));
        }
    }

    
   string shortestCommonSupersequence(string str1, string str2) {
    int n=str1.size();
    int m=str2.size();
    memset(dp,-1,sizeof(dp));
    lcs(0,0,str1,str2);
    int i=0,j=0;
    string ans="";
while(i<n && j<m){
    if(str1[i]==str2[j]){
        ans.push_back(str1[i]);
        i++;
        j++;
    }
    else if(dp[i+1][j]>dp[i][j+1]){
        ans.push_back(str1[i]);
        i++;
    }
    else{
        ans.push_back(str2[j]);
        j++;

    }
  
    
    }
    return ans+str1.substr(i)+str2.substr(j);
}
};