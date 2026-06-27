// now i am doing the closest Subsequence sum 
// this is same as the form 6
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int minAbsDifference(vector<int>& nums, int goal){
        int n = nums.size();
        int mid=n/2;
        vector<int> left, right;
        for(int mask=0;mask<(1<<mid);mask++){
            int sum = 0;
            for(int i=0;i<mid;i++){
                if(mask&(1<<i)){
                    sum+=nums[i];
                }
            }
            left.push_back(sum);
        }
        int sz=n-mid;
        for(int mask=0;mask<(1<<sz);mask++){
            int sum = 0;
            for(int i=0;i<sz;i++){
                if(mask&(1<<i)){
                    sum+=nums[mid+i];
                }
            }
            right.push_back(sum);
        }
      
        sort(right.begin(),right.end());
int ans=abs(goal);
for(int leftSum:left){
    int target=goal-leftSum;
    auto it=lower_bound(right.begin(),right.end(),target);
    if(it!=right.end()){
        ans=min(ans,abs(goal-(leftSum+*it)));

    }
    if(it!=right.begin()){
        it--;
        ans=min(ans,abs(goal-(leftSum+*it)));
    }
}
return ans;
    }
};