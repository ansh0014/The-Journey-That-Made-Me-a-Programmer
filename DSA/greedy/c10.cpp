// now i am doing the minimum number of operations to make array empty
// we have to delete the elements like we can choose two elements with the equal value and delete them in one operation. we can do this until the array is empty. so the minimum number of operations will be the size of the array - maximum frequency of the element in the array + 1. lets write the code for this problem
// choose three elements with the equal value and delete them in one operation. we can do this until the array is empty. so the minimum number of operations will be the size of the array - maximum frequency of the element in the array + 1. lets write the code for this problem
// approach we can use the greedy approach
// we have to use operations to make the array empty. we can choose two elements with the equal value and delete them in one operation. we can do this until the array is empty. so the minimum number of operations will be the size of the array - maximum frequency of the element in the array + 1. lets write the code for this problem
// 
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int minOperations(vector<int>& nums) {
    unordered_map<int,int> mp;
    for(int x:nums){
        mp[x]++;
    }
    int ans=0;
    for(auto it:mp){
        int freq=it.second;
        if(freq==1){
            return -1;
        }
        if(freq%3==0){
            ans+=freq/3;

    }else if(freq%3==1){
        ans+=(freq-4)/3+2;
    }else{
        ans+=(freq-2)/3+1;
    }

}
return ans;

}
};
