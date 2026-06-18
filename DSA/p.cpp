// now i am doing hte maximum number of jumps to reach the last index
// this is greedy approach
// first i have to understand the what is target means
// target means the last index of the array and i have to reach there
// target help to allow the jumb 
// -target<=nums[j]-nums[i]<=target
// i have use the greedy approach to solve this problem
// i have to use two pointer approach to solve this problem

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maximumJumps(vector<int>&nums,int target){
        int n=nums.size();
        int maxjump=0;
        int i=0;
        while(i<n-1){
            int j=i+1;
            bool flag=false;
            while(j<n){
                if(nums[j]-nums[i]>=-target && nums[j]-nums[i]<=target){
                    flag=true;
                    break;
                }
                j++;
            }
            if(flag){
                maxjump++;
                i=j;
            }
            else{
                return -1;
            }
        }
        return maxjump;
    }
};