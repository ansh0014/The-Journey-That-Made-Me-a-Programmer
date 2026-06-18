// now i am doing the Rod cutting problem using the form 4
#include<bits/stdc++.h>
using namespace std;
int n;
int x[1001];
int dp[1001][1001];
int rec(int l, int r){
    if(l>r){
        return 0;

    }
    if(l+1==r){
        return 0;
    }
    // cache it
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    int ans=1e9;
    for(int p=l+1;p<r-1;p++){
        ans=min(ans,x[r]-x[l]+rec(l,p)+rec(p,r));
    }
    return dp[l][r]=ans;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        // implementation for rod cutting problem
        cin>>x[i];

    }
    x[0]=0;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n+1)<<endl;
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