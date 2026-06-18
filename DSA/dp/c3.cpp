// now we are doing the climbing problem with the dp
#include<bits/stdc++.h>
using namespace std;
int n;
int dp[100000];
int rec(int level){ // rec->number of ways to populate [level---n-1] rows for a valid configuration

if(level>n) return 0;
if(level==n) return 1;
if(dp[level]!=-1) return dp[level];
int ans=0;
for(int step=1;step<=3;step++){
    if(level+step<=n){
        int ways=rec(level+step);
        ans+=ways;
    }
}
return dp[level]=ans;
}
void solve(){
cin>>n;
memset(dp,-1,sizeof(dp));
cout<<rec(0)<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1; 
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
}