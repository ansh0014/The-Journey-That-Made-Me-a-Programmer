// now i am doing hte can i win
// i the 100 game two players take turns adding to running total any integer from 1 to 10. the player who first caused the running total to reach or exceed 100 wins
// lets take if i change the game so the player cannot re-use integers.
// for example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >=100
// given an integer maxChoosableInteger and another integer desiredTotal, return true if the first player to move can force a win, otherwise return false.
// i think we can use the bitmask for the mask of the numbers and then we will use the dp for the transition of the mask and then we will use the backtracking to find if the first player to move can force a win, otherwise return false.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool canIWin(int maxChoosableInteger, int desiredTotal){
        if(desiredTotal<=0) return true;
        if((maxChoosableInteger*(maxChoosableInteger+1))/2<desiredTotal) return false;
        unordered_map<int,bool> dp;
        function<bool(int,int)> dfs=[&](int mask,int total){
            if(dp.count(mask)) return dp[mask];
            for(int i=0;i<maxChoosableInteger;i++){
                if(!(mask&(1<<i))){
                    if(total+i+1>=desiredTotal || !dfs(mask|(1<<i),total+i+1)){
                        return dp[mask]=true;
                    }
                }
            }
            return dp[mask]=false;
        };
        return dfs(0,0);
    }
};
