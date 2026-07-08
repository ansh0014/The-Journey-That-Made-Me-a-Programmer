// now i am doing the maximum number of elements in subsets
/*
You can place the selected elements in a 0-indexed array such that it follows the pattern: [x, x2, x4, ..., xk/2, xk, xk/2, ..., x4, x2, x] (Note that k can be be any non-negative power of 2). For example, [2, 4, 16, 4, 2] and [3, 9, 3] follow the pattern while [2, 4, 8, 4, 2] does not.
Return the maximum number of elements in a subset that satisfies these conditions.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int maximumLength(vector<int>& nums) {
int n = nums.size();
unordered_map<long long,int> mp;
for(int i=0;i<n;i++){
    mp[nums[i]]++;
}
int ans=1;
if(mp.count(1)){
    if(mp[1]%2==0) ans=max(ans,mp[1]-1);
    else{
        ans=max(ans,mp[1]);
    }
}
for(auto &it:mp)
{
    if(it.first==1) continue;
    long long cur=it.first;
    int count=0;



while(mp[cur]>=2){
count+=2;
if(cur>31622){
    break;
}
cur=cur*cur;
}

if(mp[cur]>=1) count++;
else count--;
ans=max(ans,count);
}
return ans;
}
};
