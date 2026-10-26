// now i am doing teh valid anagram
// i have return false and true
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:

   bool isAnagram(string s, string t) {
unordered_map<char,int>mp;
int n=s.size();
int m=t.size();
for(auto it:s){
    mp[it]++;
}
for(auto it1:t){
mp[it1]--;
}
for(auto it=mp.begin();it!=mp.end();it++){
    if(it->second!=0){
        return false;
    }
}
if(mp.begin()->second!=0){
    return false;
}else{
    return true;
}
return true;

    }
};