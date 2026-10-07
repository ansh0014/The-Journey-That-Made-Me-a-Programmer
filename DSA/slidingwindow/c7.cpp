// now i am doing the maximize greatness of an array
// i have given an 0-indexed integer array nums. i have allowed to permute nums into a new array perm of i choosing
// i define the greatness of nums be the number of indices 0<=i<nums.lenghts for which perm[i]>nums[i].
// return the maximum possible greatness i can achieve after permuting nums
// this question of greedy and sorting
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[ans]){
                ans++;
            }
        }
        return ans;
    }
};