// now i am doing the number of paths with max score
// i have given a square board of characters. you can move on the board starting at bottom right square markded with the character 'S'
// i have to need to reach the top left square marked with hte character 'E' the rest of the squares are labeled eithter with a numberic character 1,2,---9 or with an obstacle 'X'. in one move you can go up , left or up-left(diagonlly) only if there is no obstacle there.
// return al list of two integers : the first integer is the maximum sum of numeric characteers you can collect and the second is hte number of such paths that you can take get that maximum sum,take modulo 10^9+7. if there is no path, return [0,0]
// approach we used the dp form 1 take it and not take it and store the max sum and number of paths in dp array
// lets talk abotu the dp state we will use dp[i][j] to store the max sum and number of paths to reach the cell (i,j) from the cell (0,0) and we will use the previous cells to calculate the current cell
// now what is transition we can come to the cell (i,j) from the cell (i-1,j),(i,j-1),(i-1,j-1) and we will take the max sum from these cells and add the current cell value to it and also we will take the number of paths from these cells and add them to get the number of paths to reach the cell (i,j)
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> pathsWithMaxScore(vector<string>& board){
        int n=board.size();
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{-1,0}));
        dp[n-1][n-1]={0,1};
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(board[i][j]=='X') continue;
                if(i==n-1 && j==n-1) continue;
                int maxSum=-1;
                int count=0;
                if(i+1<n){
                    maxSum=max(maxSum,dp[i+1][j].first);
                }
                if(j+1<n){
                    maxSum=max(maxSum,dp[i][j+1].first);
                }
                if(i+1<n && j+1<n){
                    maxSum=max(maxSum,dp[i+1][j+1].first);
                }

                if(maxSum==-1) continue;
                if(i+1<n && dp[i+1][j].first==maxSum){
                    count=(count+dp[i+1][j].second)%1000000007;
                }
                if(j+1<n && dp[i][j+1].first==maxSum){
                    count=(count+dp[i][j+1].second)%1000000007;
                }
                if(i+1<n && j+1<n && dp[i+1][j+1].first==maxSum){
                    count=(count+dp[i+1][j+1].second)%1000000007;
                }
                int val=0;
               if(board[i][j]>='1' && board[i][j]<='9'){
                    val=board[i][j]-'0';
                }
               dp[i][j]={maxSum+val,count};
            }
       
        }
         if(dp[0][0].first==-1){
                return {0,0};
        }
        return {dp[0][0].first,dp[0][0].second};
    }
};