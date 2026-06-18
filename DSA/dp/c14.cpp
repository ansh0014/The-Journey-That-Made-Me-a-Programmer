// right now i am doing the substraction problem
#include<bits/stdc++.h>
using namespace std;
int dp[1001];
int rec(int x){
    // basecase
if(x==0){
    return 0;
}
// cache it
if(dp[x]!=-1){
    return dp[x];
}
// compute
int ans=0;
for(int m=1;m<=x;m++){
    ans=max(ans,rec(x-(1<<m)));
}
dp[x]=ans;
return ans;
}


void solve(){
    int x;
    cin>>x;
    cout<<rec(x)<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    for(int i=0;i<t;i++){
        solve();
    }
}