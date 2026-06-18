// now i am doing the find hte minimum in rotated sorted array
// approach first i have to find the pivot element and then i will return the minimum element
// i have to rotated the array in such way way minimum element come at the middle i ahve to keep low at index 0 and hight at index n-1 and then i will find the mid element and then i will compare the mid element with the high element if mid element is less than high element then i will move the high pointer to mid else i will move the low pointer to mid+1
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// class Solution{
// public:
// int findMin(vector<int>& nums){
//     int n=nums.size();
//     int low=0;
//     int high=n-1;
//     while(low<high){
//         int mid=low+(high-low)/2;
//         if(nums[mid]<nums[high]){
//             high=mid;
//         }
//         else if(nums[mid]>nums[high]){
//             low=mid+1;
//         }
//         else{
//             high--;
//         }
//     }
//     return nums[low];
// }
// };
// now i am doing the peek element 
// approach first i have to find the peek which is the greater element in theri neighbour hood i have to return the index of peek 
//  i have to apply the binary search then compare the mid element with its left and right element if mid element is greater than both then i will return the mid index else if mid element is less than its left element then i will move the high pointer to mid-1 else i will move the low pointer to mid+1
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int findPeakElement(vector<int>& nums){
int n=nums.size();
int low=0;
int h=n-1;
while(low<=h){
    int mid=low+(h-low)/2;
    if((mid==0 || nums[mid]>nums[mid-1]) && (mid==n-1 || nums[mid]>nums[mid+1])){
        return mid;
    }
    else if(mid>0 && nums[mid]<nums[mid-1]){
        h=mid-1;
    }
    else{
        low=mid+1;
}

}
return -1;
}
};