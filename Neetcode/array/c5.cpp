// given an unosorted integer array nums. Return the smallest positive integer that is not present in nums.
// i have must implemented an algorithm that runs in O(n) time and uses constant extra space
// i think the best approach to solve this problem is to use the index of the array as a hash key and the sign of the number as a presence detector.
// first we will iterate over the array and for each number we will mark the index of that number as negative. then we will iterate over the array again and the first positive number we find is the smallest positive integer that is not present in nums.
// the number we return the number
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
       int firstMissingPositive(vector<int>& nums) {
    int n=nums.size();
    int index=0;
    // first we will iterate over the array and for each number we will mark the negative
    for(int i=0;i<n;i++){
        if(nums[i]<=0){
            nums[i]=n+1; // this condition is because if the number is less then or equal to 0 
        }
      
    }
    for(int i=0;i<n;i++){
        int x=abs(nums[i]);
    if(x>=1 && x<=n){
        int index=x-1;
        if(nums[index]>0){
            nums[index]=-nums[index]; // this condition is because if the number is greater then 0 then we will mark it as negative
        }
    }
    }
    
for(int i=0;i<n;i++){
    if(nums[i]>0){
        return i+1;
    }

}
    
    return n+1;
    } 
    };
