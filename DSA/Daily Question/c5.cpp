// now i am doing the partition equal array according to given the pivot
// i have given an array of integers and a pivot element
// this quick sort partitioning algorithm
#include<bits/stdc++.h>
using namespace std;
class Solution{
   vector<int>pivotArray(vector<int>& nums,int pivot){
    int n=nums.size();
    vector<int> ans(n);
    vector<int> less,greater, equal;
    for(int i=0;i<n;i++){
        if(nums[i]<pivot){
            less.push_back(nums[i]);
        }else if(nums[i]>pivot){
            greater.push_back(nums[i]);
        }else{
            equal.push_back(nums[i]);
        }
    }
    int k=0;
    for(int i=0;i<less.size();i++){
        ans[k++]=less[i];
    }
    for(int i=0;i<equal.size();i++){
        ans[k++]=equal[i];
    }
    for(int i=0;i<greater.size();i++){
        ans[k++]=greater[i];
    }
    return ans;
   } 
};