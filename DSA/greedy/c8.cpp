// now i am doing the patching array
// given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1,n] inclusive can be formed byt eh sum of the some element in the array.
// return the minimum number of patches required.
// we have to use the greedy approach to solve this problem. we will keep track of the current range of numbers that can be formed using the elements in the array and the patches we have added so far. we will iterate through the array and for each element, we will check if it is within the current range. if it is, we will update the current range to include this element. if it is not, we will add a patch (the smallest number that can be formed) to extend the current range until it includes this element. we will continue this process until we have covered the entire range [1,n].
// lets type the psedu do code for this problem
// first we will initialize a variable "patches" to 0, which will keep track of the number of patches added. we will also initialize a variable "current_range" to 1, which represents the current range of numbers that can be formed using the elements in the array and the patches added so far. we will iterate through the array using a for loop and for each element, we will check if it is within the current range. if it is, we will update the current range to include this element by adding it to the current range. if it is not, we will add a patch (the smallest number that can be formed) to extend the current range until it includes this element. we will continue this process until we have covered the entire range [1,n]. finally, we will return the value of "patches" as the minimum number of patches required.
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int minPatches(vector<int>& nums, int n) {
        long long current_range = 1; // current range of numbers that can be formed
        int patches = 0; // number of patches added
        int i = 0; // index for iterating through the array
        
        while (current_range <= n) {
            if (i < nums.size() && nums[i] <= current_range) {
                // if the current element is within the current range, update the range
                current_range += nums[i];
                i++;
            } else {
                // if the current element is not within the current range, add a patch
                current_range += current_range; // add the smallest number that can be formed
                patches++;
            }
        }
        
        return patches;
    }
};