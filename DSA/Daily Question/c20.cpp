// now we are doing the maximum ice creams Bars
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int maxIceCream(vector<int>& cost,int coins){
    sort(cost.begin(),cost.end());
    if(coins<cost[0]) return 0;
    int ans=0;
    for(int i=0;i<cost.size();i++){
        if(coins>=cost[i]){
            coins-=cost[i];
            ans++;
        }
        else break;
    }
    return ans;
}
};