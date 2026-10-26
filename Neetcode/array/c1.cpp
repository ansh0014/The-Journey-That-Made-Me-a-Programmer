// now i am doing the contains duplicate
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
       bool containsDuplicate(vector<int>& nums) {
     unordered_map<int,int>mp;
     for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
     }
     for(auto it:mp){
        if(it.second>1){
            return true;
        }
     }
     return false;
    }
};