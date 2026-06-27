// now we are doing the count subaars with majority element 11
// i have given the an interger array nums and a integer target
// return the number of subarrays of nums in which target is the majority element
// we used prefix sum and map for that and we have to find the number of subarrays of nums in which target is the majority element
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();
        long long count = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == target)
                nums[i] = 1;
            else
                nums[i] = -1;
        }

        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        int shift = n + 1;
        vector<long long> freq(2 * n + 3, 0);

        freq[shift] = 1;

        long long ans = 0;
        int last = 0;

        for(int i = 1; i <= n; i++){

            if(prefix[i] > last){
                ans += freq[last + shift];
            }
            else{
                ans -= freq[prefix[i] + shift];
            }

            count += ans;

            freq[prefix[i] + shift]++;

            last = prefix[i];
        }

        return count;
    }
};
