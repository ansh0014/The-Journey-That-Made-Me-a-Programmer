// now i am doing the find all Duplicates in an array
// i used hash map then i will check the frequency of each element and if the frequency is greater than 1 then i will push it in the answer vector
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
// vector<int> findDuplicates(vector<int>&nums){
//     int n=nums.size();
//     vector<int> ans;
//     unordered_map<int,int>m;
//     for(int i=0;i<n;i++){
//         m[nums[i]]++;
//     }
//     for(auto it:m){
//         if(it.second>1){
//             ans.push_back(it.first);
//         }
//     }
//     return ans;
// }
// };
