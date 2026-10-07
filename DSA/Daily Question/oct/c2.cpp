// now i am doing the sliding window median
// teh median is the middle value in an ordered integer list. if the size of the list is even , there is no middle value. So the median is the mean of the two middle values
// for example if arr=[2,3,4] the median is 3.
// for examples if arr=[1,2,3,4] the median is (2+3)/2=2.5
// i have given an integer arry nums and an integer k. There is sliding wondow of size k which is moving form the very left of the arry to the very right. i can only see the k numbers in the window each time the sliding window moves right byone posjtion
// return the midna ray for each window in the roginal arry . answer withing 1e-5 of the actual value will be aceepted
//approach  we have to used the sliding window + binary seach
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> ans;
    vector<int> window;
    for(int i=0;i<k;i++){
        window.push_back(nums[i]);
    }
    sort(window.begin(),window.end());
    for(int i=k;i<=nums.size();i++){
        if(k%2==1){
            ans.push_back(window[k/2]);
        }
        else{
            long long a=window[k/2];
            long long b=window[k/2-1];
            ans.push_back((a+b)/2.0);
        }
        if(i<nums.size()){
            auto removepos=lower_bound(window.begin(),window.end(),nums[i-k]);
            window.erase(removepos);
        }
        auto insertpos=lower_bound(window.begin(),window.end(),nums[i]);
        window.insert(insertpos,nums[i]);
    }
    return ans;

}
};

