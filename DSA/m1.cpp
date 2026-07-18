// now i am doing the sum of GCD of formed pairs
// i have gven an array of nums of length n.
// Construct an array prefixGcd where for each index i,
// let mxi=max(nums[0], nums[1],..., nums[i]).
// prefixGcd[i]=gcd(nums[i],mxi)
// after constructing prefixGcd
// sort preficGcd is non-decreasing order.
// form pairs by taking the smalles unpaired element and the largest unpaired element.
// Repeat this process until no more pairs can be formed.
// for each formed pair, compute the gcd of the two elements
// if n is odd the middle element in the prefixGcd array remains. unpaired and should be ignored.
// return an integer denoting the sum fo gcd values of all formed pairs.
// approach: we can use two pointer approach to form pairs and calculate the sum of GCD of formed pairs.
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:

long long gcdSum(vector<int>& nums){
    int n=nums.size();
    vector<int> prefixGcd(n);
    int mxi=nums[0];
  prefixGcd[0]=gcd(nums[0], mxi);
    for(int i=1; i<n; i++){
        mxi=max(mxi, nums[i]);
        prefixGcd[i]=gcd(nums[i], mxi);
    }
    sort(prefixGcd.begin(), prefixGcd.end());
    long long sum=0;
    int left=0, right=n-1;
    while(left<right){
        sum+=gcd(prefixGcd[left], prefixGcd[right]);
        left++;
        right--;
    }
    return sum;
}
};