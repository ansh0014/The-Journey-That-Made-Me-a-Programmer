// now i am doing the subarrays with k different integers
// i have to generating all the subarrays and then i have to check if the subarray has k different integers then i have to count that subarray
// i udnerstand k is the target that i got measn if k=2 i need atleast 2 different integers
// approach i have to used the two pointer
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
// int subarrayWithDistinct(vector<int> &nums,int k){
//     int n=nums.size();
//     int count=0;
//     unordered_map<int,int>mp;
//     int l=0;
// // i undersntand i have to check the pointer l and r they don't have to be same and then i have to check if the size of the map is less than k then i have to move the right pointer and if the size of the map is greater than k then i have to move the left pointer and if the size of the map is equal to k then i have to count the subarray
//     for(int r=0;r<n;r++){
//         mp[nums[r]]++;
//         while(mp.size()>k){
//             mp[nums[l]]--;
//             if(mp[nums[l]]==0){
//                 mp.erase(nums[l]);
//             }
//             l++;
//         }
//    count+=r-l+1;
//     }
//     return count;

// }};
// now i am doing the sum of distances
