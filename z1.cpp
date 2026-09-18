// now i am doing the lexicographically smalles premuatation greater than target
// i have given string s and target both having length n, consisting of lowercase English letters.
// return the lexicographically smalles permutation of s that is strictly greater than target. if no permuatation of s is lexicographically strictly greater than target, return an empty string.
// A string a is lexicographically strictly greater than a string b ( of the same length ) if the first position kwhere a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b.
// first i have i have given string s and targwt
// smalles permuation i have thing about the backtrack but i have also give target string so i have to check if the permuation is greater than target or not
// approach i used backtracking
// now i have think how i apply the backtrack 
// lets say i have given string s and target both having length n, consisting of lowercase English letters.
// 
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:

    int backtrack(string& s, string& target, int index, bool isGreater, vector<int>& count, string& ans){

    if(index==s.size()){
        return isGreater;

    }
    for(int i=0;i<26;i++){
        if(count[i]==0){
            continue;
        }
        char c='a'+i;
        if(!isGreater && c<target[index]){
            continue;
        }
        if(c==target[index]){
            count[i]--;
            ans.push_back(c);
            if(backtrack(s,target,index+1,isGreater,count,ans)){
                return 1;
            }
            ans.pop_back();
            count[i]++;
        }
        else{
            count[i]--;
            ans.push_back(c);
            if(backtrack(s,target,index+1,true,count,ans)){
                return 1;
            }
            ans.pop_back();
            count[i]++;
        }
    }
    return 0;
    }
    string lexGreaterPermutation(string s, string target) {
    int n=s.size();
    sort(s.begin(),s.end());
    vector<int> count(26,0);
    for(int i=0;i<n;i++){
        count[s[i]-'a']++;
        
    }
    string ans="";
    if(backtrack(s,target,0,false,count,ans)){
        return ans;
    }
 return "";

}
};