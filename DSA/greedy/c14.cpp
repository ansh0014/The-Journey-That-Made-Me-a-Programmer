// i have given an integer array planks, where planks[i] represents the height of the ith wooden plan. Each plank has a width of unit
// i want to build a fence consisiting of planks that allhave the same height
// you may either use a plank as is or combine exactly two distinct orginal planks into single plank whose height equals the sum of the height. 
// Each original plank can be used at most onec and not all original planks need to be used.
// return the maximum possible widht of the fence that can be build
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maximumWidth(vector<int>& planks){
        typedef long long ll;
        unordered_map<ll,int> freq;
        for(auto it:planks){
            freq[it]++;
        }
    // as we know that map can't access elements by index so we will use vector to store the unique heights of the planks
    vector<pair<ll,int>>vec(freq.begin(),freq.end());
    int n=vec.size();
    unordered_map<ll,int> mpp;
    for(auto it:vec){
        mpp[it.first]=it.second;
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            ll targetH=vec[i].first+vec[j].first;
            if(i==j){
                mpp[targetH]+=vec[i].second/2;
            }else{
                mpp[targetH]+=min(vec[i].second, vec[j].second);
            }
        }
    }
    int ans=0;
    for(auto &it:mpp){
        ans=max(ans,it.second);
    }
    return ans;
}
};