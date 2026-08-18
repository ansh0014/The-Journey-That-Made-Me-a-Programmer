// now i am doing the super egg drop
// i have given k indentical eggs and i have access to building with n floors labeled from 1 to n.
// i know that there exists a floor f where 0<=f<=n such that any egg dropped at floor higher than f will break, and any egg dropped at or below floor f will not break.
// each move , i may take an unbroken egg and drop if rom any floor x . I f the egg breaks i can no longer use it. However , if the egg does not break, i may reuse it in future moves
// return the minimum number of move that i need to detemine with certainty what the value of f is
// we used the dp for this problem. state is dp[k][n] where k is the number of eggs and n is the number of floors
// transition if we drop the egg from floor x then if the egg breaks then we have k-1 eggs and x-1 floors left and if the egg does not break then we have k eggs and n-x floors left. so we have to take the maximum of both cases and add 1 to it. we have to do this for all floors and take the minimum of all floors.
// but this is not optimal solution. 
#include<bits/stdc++.h>
using namespace std;
class Solution{
    int dp[101][10001];
    public:
    int memo(int egg, int floor){
        // base case
        if(floor == 0 || floor == 1) return floor;
        if(egg == 1) return floor;
        // cache dp
        if(dp[egg][floor] != -1) return dp[egg][floor];
int low=1;
int hight=floor;
int ans=INT_MAX;
while(low<=hight){
    int mid=low+(hight-low)/2;
     int breakegg=memo(egg-1,mid-1);
    int notbreakegg=memo(egg,floor-mid);
    int currentans=1+max(breakegg,notbreakegg);
    ans=min(ans,currentans);
    if(breakegg<notbreakegg){
        low=mid+1;
    }
    else{
        hight=mid-1;
    }
}
return dp[egg][floor]=ans;



}
int superEggDrop(int k,int n){
    memset(dp, -1, sizeof(dp));
    return memo(k,n);

}
};

