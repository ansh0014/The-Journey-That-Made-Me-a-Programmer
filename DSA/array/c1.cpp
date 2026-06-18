// longest subarray with the sum k
// we do the concept of the prefix sum and store the first occurrence of the prefix sum in the map
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int longestSubarrayWithSumk(vector<int>a,long long k){
    unordered_map<long long,int>mp;
    int maxlen=0;
    long long sum=0;
for(int i=0;i<a.size();i++){
    sum+=a[i];
    if(sum==k){
        maxlen=max(maxlen,i+1);

    }
    int rem=sum-k;
    if(mp.find(rem)!=mp.end()){
        int len=i-mp[rem];
        maxlen=max(maxlen,len);

    }
    if(mp.find(sum)==mp.end()){
        mp[sum]=i;
    }
    return maxlen;
}
}