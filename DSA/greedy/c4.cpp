// now i am doing the overlapping intervals
// i have to merge the overlapping intervals and then i have to return the non overlapping intervals
// approach first i have to sort the intervals based on the starting time and then i have to compare the ending time of the previous interval with the starting time of the current interval if they are overlapping then i will merge them else i will add the current interval to the answer
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n=intervals.size();
    if(n==0){
        return 0;
    }
    sort(intervals.begin(),intervals.end());
    int count=0;
    int end=intervals[0][1];
    for(int i=1;i<n;i++){
    }
};