// now i am doing the find x value of array
// i ahve given array of positive integers nums and postive integers
// i have to allowed to perform an operation once on nums, where in each operation i can remove any non-overlapping prefix and suffix from nums such that nums remains non-empty
// i need to find the x-value of nums which is the number of ways to perform this operations so that product reaming elements leaves a remainder x whenr dividded by k.
// return the array result of size k where result[x] is the x-value of nums for each x from 0 to k - 1.
// a prefix of an array is a subarray that contains the first elements of the array, and a suffix of an array is a subarray that contains the last elements of the array.
// a suffix of an array is a subarray that contains the last elements of the array.
// first thorught listening the word binary search 
// now divide the prefix and suffix into two parts and then we will check if the product of the remaining elements leaves a remainder x when divided by k and if it does then we will increment the count of x in the result array.
// using the prefix and suffix we can find the product of the remaining elements in O(n) time complexity and then we can check if the product leaves a remainder x when divided by k in O(1) time complexity.
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
       vector<long long> resultArray(vector<int>& nums, int k) {
    vector<long long> dp(k, 0);
vector<long long> result(k, 0);
    int n = nums.size();
    for (int nums:nums){
        vector<long long> newdp(k, 0);
        int value = nums % k;   
        newdp[value]++;
        for(int r=0;r<k;r++){
            if(dp[r]==0){
continue;
            }
            int newr=(long long)r*value%k;
            newdp[newr]+=dp[r];
        }
        for(int r=0;r<k;r++){
            result[r]+=newdp[r];
        }
        dp = newdp;
    } 
    return result;
    }
};