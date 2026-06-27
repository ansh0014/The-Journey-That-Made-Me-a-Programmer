// now we are doing the subarrys with majority Element 1
// i have given an integer array nums and an integer target.
// return the number of subaarys of nums in which targe is the majority elemtn
// the majority element of a subarrya is the element that appears strictly more than half of the times in that subarray

// approach do the brute force geneate all sub array
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int countMajoritySubarrays(vector<int> &nums,int target){
	int n=nums.size();
	int ans=0;
for(int i = 0; i < n; i++){
    int cnt = 0;

    for(int j = i; j < n; j++){

        if(nums[j] == target)
            cnt++;

        int len = j - i + 1;

        if(cnt > len / 2)
            ans++;
    }
}
	return ans;
}
};