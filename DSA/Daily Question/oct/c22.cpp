// right now i am doing the maximum alternating sum of squrares
// i have given an integer array nums .i may rearrange the elemtns in ay order.
// the alternating score of any arr defined as
// score=arr[0]^2-arr[1]^2+arr[2]^2-arr[3]^2+==
// logic i make one vector ans then first i have sort the array in decreasing order then i will push the first element in ans then i will push the second element in ans then i will push the third element in ans and so on
// then i have to calculate the score of ans and return it
// return an integer denoting the maximum possible alternating score of nums after arraanging its elements
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
     long long maxAlternatingSum(vector<int>& nums) {
  int n=nums.size();
 
  sort(nums.begin(),nums.end());
  
  long long score=0;
  for(int j=0;j<n/2;j++)
  {
    long long sq=1LL*nums[j]*nums[j];
   score-=sq;
    
  }
  for(int j=n/2;j<n;j++)
  {
    long long sq=1LL*nums[j]*nums[j];
   score+=sq;

  }
  return score;

    }
};