// // now i am doing he kth missing positive number
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     int findKthPositive(vector<int>& arr,int k){
//         int n=arr.size();
//         int l=0;
//         int h=n-1;
//         while(l<=h){
//             int mid=l+(h-l)/2;
//             if(arr[mid]-mid-1<k){
//                 l=mid+1;
//             }
//             else{
//                 h=mid-1;
//             }

//         }
//         return l+k;
//     }

// };
// now i am doing the array partition
// i used the pair data structure for that and then i sort the array and then i sum the first element of the pair and return the sum
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
//     int arrayPairSum(vector<int>& nums) {
//      vector<pair<int,int>>v;
//      for(int i=0;i<nums.size();i++){
//          v.push_back({nums[i],i});
//      }
//         sort(v.begin(),v.end());
//         int sum=0;
//         for(int i=0;i<v.size();i+=2){
//             sum+=v[i].first;
//         }
//         return sum;
//     }

// };
// now i am doing minimum pair removal to sort array 11
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSorted(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i-1]) return false;
        }   return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while(!isSorted(nums)) {
            int minSum = INT_MAX;
            int idx = 0;
            for(int i = 0; i < nums.size() - 1; i++) {
                if(nums[i] + nums[i+1] < minSum) {
                    minSum = nums[i] + nums[i+1];
                    idx = i;
                }
            }
            nums[idx] = nums[idx] + nums[idx+1];
            nums.erase(nums.begin() + idx + 1);

            operations++;
        }     
         return operations;
    }
};