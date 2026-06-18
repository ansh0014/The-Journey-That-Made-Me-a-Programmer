// now i am doing the merge intervals 
// first i sort the inteval for that i want to use the 
#include<bits/stdc++.h>
using namespace std;
class{
public:
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>>ans;
    sort(intervals.begin(),intervals.end());
    for(int i=0;i<intervals.size();i++){
        if(ans.empty()||ans.back()[1]<intervals[i][0]){
            ans.push_back(intervals[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }
    }
    return ans;
}
};