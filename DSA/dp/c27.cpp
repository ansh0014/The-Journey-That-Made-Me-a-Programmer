// now i am doing the guess number higher or lower 11
// we are playing the guess game. the game is as follows: i pick a number from 1 to n. you have to guess which number i picked. every time you guess wrong, i will tell you whether the number i picked is higher or lower than your guess. however, when you guess a particular number x, and you guess wrong, you will pay $x. you win the game when you guess the number i picked.
// given a particular n, return the minimum amount of money you need to guarantee a win regardless
// approach this question of game theory of dp 
// dp+binary search
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int dp[201][201];
    int memo(int start, int end){
        if(start>=end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
  int ans=INT_MAX;
  for(int i=start;i<=end;i++){
    int cost=i+max(memo(start,i-1),memo(i+1,end));
    ans=min(ans,cost);
  }

      return dp[start][end]=ans;
    }
    int getMoneyAmount(int n){
memset(dp,-1,sizeof(dp));
return memo(1,n);
    }
};
