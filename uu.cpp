// now i am doing the Minimum path sum
// given a m*n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path
// i can only move either down or right at any point in time
// #include <bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
// int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         dp[0][0] = grid[0][0];
//         for(int i=1; i<m; i++){
//             dp[i][0] = dp[i-1][0] + grid[i][0];
//         }
//         for(int j=1; j<n; j++){
//             dp[0][j] = dp[0][j-1] + grid[0][j];
//         }
//         for(int i=1; i<m; i++){
//             for(int j=1; j<n; j++){
//                 dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };
// now i am doing the check the diviisibility by digit sum and product
//  i have given a positive integer n. Determine whether n is divisible by the sum of the following two values:
// the digit sum of n (the sum of its digits)
// the digit product of n (the product of its digits)
// return ture if n is divisible by this sum; otherwise, return false
// approach we used loop and write the logic
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool checkDivisibility(int n){
        int sum=0;
        int product=1;
        int num=n;
      while(num>0){
            int digit=num%10;
            sum+=digit;
            product*=digit;
            num/=10;
        }
        int total=sum+product;
        if(n%total==0){
            return true;
        }
        else{
            return false;
        }
    }
};