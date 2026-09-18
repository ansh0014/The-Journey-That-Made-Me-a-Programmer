// now i am doing the best time to buy and sell stock 2
// i have given an integer array prices where prices[i] is the price of a given stock on ith day
// on each day, i ma decide the buy and / or sell the stock.
// i can only hold at most one share of the stock at any time. however, i can sell and buty stock multiple times on the same day, ensuring i never hold more the one share of the stock
// return the maximum profit i can achieve
#include<bits/stdc++.h>
using namespace std;
class Solution{
    vector<int>dp;
    int memo(int i, vector<int>& prices) {
        if(i >= prices.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int profit = 0;
        for(int j = i; j < prices.size(); j++) {
            if(prices[j] > prices[i]) {
                profit = max(profit, prices[j] - prices[i] + memo(j + 1, prices));
            }
        }
        return dp[i] = profit;
    }
    public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        dp.resize(n, -1);
        return memo(0, prices);
    }
};