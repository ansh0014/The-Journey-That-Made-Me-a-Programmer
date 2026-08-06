// now i am doing the predict the winner 
// i have given an integer array nums. 
// Two players are playing a game with this array: player 1 and player 2
// player 1 and player 2 take turns, with player 1 starting firs.t Both players start the game with score of 0.
// at each turn the plaer take one of the nuber from either end of the array which reduces the size of the array by 1. The player adds the chose number to their score. The game ends when thre are no more lemenst int he array
// return the true if player 1 can win. if the scores of both players are equal, then player 1 is still the winner, and return true. You may assume that both players are playing optimally.
// we used the game theory to solve this question. we will use the dp for the transition of the scores of both players and then we will use the backtracking to find if player 1 can win or not.\

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool predictTheWinner(vector<int>& nums){
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=nums[i];
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                dp[i][j]=max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1]>=0;
    }
};