// now i am doing the group anagrams
// logic i use unordered_map and pair of string then used iterator increment and then push back the value in vector of vector of string
// decrement the value of iterator and then check if the value is not equal to end of unordered_map then push back the value in vector of vector of string
// then implement the logic of sorting the string and then push back the value in vector of vector of string
// then if the value of iterator is equal to end of unordered_map then push back the value in vector of vector of string
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
     unordered_map<string,vector<string>>mp;
     for(int i=0;i<strs.size();i++){
        string temp=strs[i];
        sort(temp.begin(),temp.end());
        mp[temp].push_back(strs[i]);
     }
     vector<vector<string>>ans;
     for(auto it=mp.begin();it!=mp.end();it++){
        ans.push_back(it->second);
       
    
     }
   
     return ans;
    }
};