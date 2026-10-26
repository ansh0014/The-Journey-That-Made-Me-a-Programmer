// right now we are doing the minimum swaps to sort by digit sum
// i have given an nums of distinct positive integers. i need to sort the array in increasing order based on the sum of the digits of each number . if tow numbers have the same digit sum the smaller number apprears first in the sorted order
// return the minimum number of swaps required to sort the array in this way
// approach we will create a vector of pairs where each pair will contain the digit sum and the number itself. then we will sort this vector based on the digit sum and if two numbers have the same digit sum we will sort them based on the number itself. after that we will find the minimum number of swaps required to sort the original array based on the sorted vector.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // we used to hashmap to store the index of each number in the original array. then we will iterate through the sorted vector and for each number we will check if it is in the correct position or not. if it is not in the correct position we will swap it with the number which is in the correct position and we will update the index of both numbers in the hashmap. we will keep doing this until all numbers are in the correct position. the number of swaps required will be equal to the number of times we had to swap two numbers.
    int digitsum(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
        int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<pair<int,int>,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({{digitsum(nums[i]),nums[i]},i});
        }
        sort(v.begin(),v.end());
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i] || v[i].second==i) continue;
            int j=i;
            int c=0;
            while(!vis[j]){
                vis[j]=1;
                j=v[j].second;
                c++;
            }
            if(c>0){
                ans+=c-1;
            }
        }
        return ans;
        }

};