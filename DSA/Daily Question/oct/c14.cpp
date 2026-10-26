// now i am doing the minimum cost to make two binary strings equal
// i have given tow binary strings s and t, both of length n, and three positive integers flipcost, swapcost, crosscost
// i have allowed to apply the following operations any number of times to the strings and t.
// choose any index i and flip s[i] or t[i] (change '0' to '1' or '1' '0' ) the cost of this operations is flipcost.
// choose two distinct indices i and j and swap s[i] either s[i] and s[j] or t[i] and t[j].
// the cost of this operation is swapcost.
// choose an index i and swap s[i] with t[i]. the cost of this operation is crossCost.
// return the integer denoting the minimum total cost needed to make the strings s and t equal.
// nice question
// we have to implement the greedy approach 
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
    int n = s.size();
    long long k=0;
    long long y=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0' && t[i]=='1'){
            k++;
        }else if(s[i]=='1' && t[i]=='0'){
            y++;
        }
    }
    long long ans=(k+y)*1LL*flipCost;
    long long pairs=min(k,y);
    long long swap=pairs*min(1ll*swapCost,2LL*flipCost)+(k+y-2*pairs)*1LL*flipCost;
    ans=min(ans,swap);
    return ans;
    }
};