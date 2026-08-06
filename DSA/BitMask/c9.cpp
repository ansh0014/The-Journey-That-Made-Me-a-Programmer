// now i am doing hte matchsticks to square
// i have given an integer array matchsticks where matchstikcs[i] is the length of ith matchstck. i want to use all matchsticks to amek one squalre. 
// i should not break any stick but i can link them and each matchstick must used exatly one time
// return true if i can make this square and false otherwise
// approach i used bitmask dp dp state is matchsticks used and we will use backtracking to find the solution
#include<bits/stdc++.h>
using namespace std;
class Solution{
    int memo(vector<int>& matchsticks, int mask, int target, int currentSum, int sidesFormed, unordered_map<int,bool>& dp){

             int n=matchsticks.size();
        if(sidesFormed==4) return true;
if(dp.count(mask)) return dp[mask];
        for(int i=0;i<n;i++){
            if(mask&(1<<i)) continue;
            if(currentSum+matchsticks[i]>target) continue;
            int newMask=mask|(1<<i);
            int newSum=(currentSum+matchsticks[i])%target;
            int newside=sidesFormed+(currentSum+matchsticks[i])/target;
            if(memo(matchsticks,newMask,target,newSum,newside,dp)){
                return dp[mask]=true;
            }
        }
        return dp[mask]=false;
    }
    public:
    bool makesquare(vector<int>& matchsticks){
   
     int n=matchsticks.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=matchsticks[i];
        }
        if(sum%4!=0) return false;
        int target=sum/4;
        sort(matchsticks.rbegin(),matchsticks.rend());
        unordered_map<int,bool> dp;
        if(matchsticks[0]>target) return false;
    return memo(matchsticks,0,target,0,0,dp);

    }
};