// now i am doing the minimum cost for tickets
// i have planned some train traveling one year in advance. The days of year in which i will travel are given as integer array days. Each day is an integer from 1 to 365
// rain tickets are sold in three different ways
// a 1-day pass is sold for costs[0] dollars, a 7-day pass is sold for costs[1] dollars, and a 30-day pass is sold for costs[2] dollars
// we used dp take it or not take form 
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
     int mincostTickets(vector<int>& days, vector<int>& costs) {
int n=days.size();
int dp[n+1];
dp[0]=0;
if(n==0) return 0;
for(int i=1;i<=n;i++){
    
    dp[i]=INT_MAX;
    // take 1 day pass
    dp[i]=min(dp[i],dp[i-1]+costs[0]);
    // take 7 day pass
    int j=i-1;
    while(j>=0 && days[j]>days[i-1]-7) j--;
    dp[i]=min(dp[i],dp[j+1]+costs[1]);
    // take 30 day pass
    j=i-1;
    while(j>=0 && days[j]>days[i-1]-30) j--;
    dp[i]=min(dp[i],dp[j+1]+costs[2]);
}
return dp[n];

     
    }
};