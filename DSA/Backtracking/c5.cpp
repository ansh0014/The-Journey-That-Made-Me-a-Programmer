// now i am doing the find the k-sum of an array
// i understand the question i have first i ahve to make the maximu sequence how i make i have to first sum of adjacent element and element is also part of sequecny then i have sorted in the decreasing order then i ihave given target i have to check the index no. of k i have to return hte value on index no.

// example [2,4,-2], k=5 subequences formed is  6,4,4,2,2,0,-2
// i have to sort the subsequences in decreasing order 6,4,4,2,2,0,-2
// how 2+4=6 then 2+(-2)=0 then 4+(-2)=2 then 2 is also part of the sequence and 4 is also part of the sequence
// but how 4 appear two time because 4 is also part of the sequence and 4 is also part of the sequence
// 2+4-2=4
// approach i have to use the backtracking to find sum of all element and then i have to sort the sum of all element in decreasing order and then i have to return the value on index no. k-1 because index start from 0
// how the backtracking i find the sum for removing the element and then i find the sum for including the element and then i have to sort the sum of all element in decreasing order and then i have to return the value on index no. k-1 because index start from 0
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
long long kSum(vector<int>& nums, int k) {
    vector<long long> sums;
    function<void(int, long long)> backtrack = [&](int index, long long currentSum) {
        if (index == nums.size()) {
            sums.push_back(currentSum);
            return;
        }
      
        backtrack(index + 1, currentSum + nums[index]);
        backtrack(index + 1, currentSum);
    };
    backtrack(0, 0);
    sort(sums.rbegin(), sums.rend());
    return sums[k - 1];

}};
// i got tle because i am doing the backtracking for all element and then i have to sort the sum of all element in decreasing order and then i have to return the value on index no. k-1 because index start from 0
