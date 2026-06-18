// now i am doing binary search question on leet code
// first question find the first and last postion of element in sorted array
// i this i have to find the lower and upper bound 
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// class Solution{
// public:
// vector<int> searchRange(vector<int>& nums,int target){
//    vector<int> ans(2,-1);
//    int n=nums.size();
//    int low=0,high=n-1;
//    while(low<=high){
//        int mid=low+(high-low)/2;
//        if(nums[mid]==target){
//            ans[0]=mid;
//            high=mid-1;
//        }
//        else if(nums[mid]>target){
//            high=mid-1;
//        }
//        else{
//            low=mid+1;
//        }
//    }
//    low=0,high=n-1;
//    while(low<=high){
//        int mid=low+(high-low)/2;
//        if(nums[mid]==target){
//            ans[1]=mid;
//            low=mid+1;
//        }
//        else if(nums[mid]>target){
//            high=mid-1;
//        }
//        else{
//            low=mid+1;
//        }
//    }
//    if(ans[0]!=-1 && ans[1]!=-1 && ans[0]>ans[1]){
//        swap(ans[0],ans[1]);
//    }
//    return ans;

// }
// };
// now i am doing the search in rotated sorted array ll
// approach first i have to rotate the array and then i have to apply binary search on it
// if i got target then i will return true else false
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// class Solution{
//     public:
//     bool search(vector<int>& nums,int target ){
//         int n=nums.size();
//         //  i think i have to find the pivot element
//         int low=0;
//         int high=n-1;
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             if(nums[mid]==target){
//                 return true;
//             }
//             if(nums[low]==nums[mid] && nums[mid]==nums[high]){
//                 low++;
//                 high--;
//                 continue;
//             }

             
//             if(nums[low]<=nums[mid]){
//                 if(target>=nums[low] && target<nums[mid]){
//                     high=mid-1;
//                 }
//                 else{
//                     low=mid+1;
//                 }
//             }
//             else{
//                 if(target>nums[mid] && target<=nums[high]){
//                     low=mid+1;
//                 }
//                 else{
//                     high=mid-1;
//                 }
//             }
//         }
//         return false;
//     }
// };
