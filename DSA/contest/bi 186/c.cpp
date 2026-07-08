// now i am doing the unique middle element
// i have given an integer array nums of size n
// return the true if the middle element of nums is unique, otherwise return false
// the middle element of nums is the element that is at index n / 2 (0
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isMiddleElementUnique(vector<int>& nums){
     int n=nums.size();
        int middle=nums[n/2];
            for(int i=0;i<n;i++){
                if(i!=n/2 && nums[i]==middle){
                    return false;
                }
            }
            return true;

    }
};