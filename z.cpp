// now i am doing the partition to K equal sum subsets
// i have an given array nums and an integer k, return true if it s possible to divide this array into k non-empty subsets whose sums are all equal.
// i used backtracking to solve this problem, i first check if the sum of the array is divisible by k, if not return false, then i create a vector of size k to store the sum of each subset, then i sort the array in descending order and then i call the backtracking function to check if we can partition the array into k equal sum subsets.
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
   bool canPartitionKSubsets(vector<int>& nums, int k) {
     int n= nums.size();
     
    }
};
