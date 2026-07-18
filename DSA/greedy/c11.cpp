#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minimumCost(vector<int>& nums,int k){
        const long long MOD=1e9+7;

        long long tops=0;
        long long cur=k;
        for(int x:nums){
            if(cur<x){
                long long diff=x-cur;
                long long rec=(diff+k-1)/k;
                tops+=rec;
                cur+=rec*1LL*k;
            }
            cur-=x;
        }
        long long a =tops;
        long long b=tops+1;
        if(a%2==0){
            a/=2;
        }
        else{
            b/=2;
        }
        return int((a%MOD)*(b%MOD)%MOD);
    }
};