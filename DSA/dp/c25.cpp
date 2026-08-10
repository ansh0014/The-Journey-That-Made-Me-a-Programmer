// now i am doing the sum of good subsequences
// i have given an integer array nums. A good subsequence is defined as a  subsequence of nums where the absolute difference betwee any two consectureve elements in the subsequence is exactly 1.
// approach i am using dp 
// first i have decide the state . Nums is state 
// then we have to find the trasition. if we take the ith element then we have to check whether the absolute difference between the ith element and the last element of the subsequence is 1 or not. if it is 1 then we can take the ith element otherwise we can't take the ith element. if we don't take the ith element then we can take any element from the remaining elements. so we have to find the maximum sum of good subsequences for both cases and return the maximum of both cases.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    static const int MOD=1e9+7;
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
    unordered_map<long long,long long>cnt;
    unordered_map<long long, long long>sum;
    for(int x : nums){
        long long ways=1;
        long long total=x;
        if(cnt.count(x-1)){
            ways=(ways+cnt[x-1])%MOD;
            total=(total+sum[x-1]+cnt[x-1]*x)%MOD;
        }
        if(cnt.count(x+1)){
            ways=(ways+cnt[x+1])%MOD;
            total=(total+sum[x+1]+cnt[x+1]*x)%MOD;
        }
        cnt[x]=(cnt[x]+ways)%MOD;
        sum[x]=(sum[x]+total)%MOD;
    }
    long long ans=0;
    for(auto it:sum){
        ans=(ans+it.second)%MOD;
    }
    return ans;
}};