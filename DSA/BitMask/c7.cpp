// now i am doing the shooping offers
// in leetcode store, there are n items to sell. Each items has a price however there are some special offers, and special offer consists of one or more different kinds of items with a sale price.
// i have given an integer array price where  price[i] is the price of the ith and an integer array needs where needs[i] is the number of pieces of ith item i want to buy
// i have given an array special where special[i] is of size n+1 where special[i][j] is the number of pieces of jth item in hte ith offer and special[i][n] is the price of ith offer.
// return  the lowest price i have to pay for exactly certain items as given where i could make optimal use of the special offers. we are not allowed to by more items than you even if that would lower the overall price. 
// i could use any of the special offers as many times as i want.
// approach we have use bitmask to represent the state of the needs and then we will use dp to store the minimum price for each state and then we will use backtracking to find the minimum price for the given needs.
#include<bits/stdc++.h>
using namespace std;
class Solution{
vector<int>dp;
int encode(vector<int>& needs){
    int state=0;
    for(int i=0;i<needs.size();i++){
        state|=(needs[i]<<i*4);
    }return state;
    }
    int memo( vector<int>& price, vector<vector<int>>& special,vector<int>&needs){
int state=encode(needs);
if(dp[state]!=-1) return dp[state];
int n=price.size();
int ans=0;
for(int i=0;i<n;i++){
    ans+=price[i]*needs[i];
}
for(auto& offer:special){
    vector<int> newNeeds=needs;
    bool valid=true;
    for(int i=0;i<n;i++){
        if(offer[i]>newNeeds[i]){
            valid=false;
            break;
        }
        newNeeds[i]-=offer[i];
    }
    if(valid){
        ans=min(ans,offer[n]+memo(price,special,newNeeds));
    }
}
return dp[state]=ans;
    
    }
    public:
        int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
dp.assign(1<<24,-1);
return memo(price,special,needs);
        }
};