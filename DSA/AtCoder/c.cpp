// now i am doing the Frog 1
// there is N stone numbered 1,2...N for each i(1<=i<=N) the height of the stone is given by h[i]. A frog is initially on stone 1 and he wants to reach stone N. The frog can jump from stone i to stone i+1 or stone i+2. If the frog jumps from stone i to stone j, the energy lost in the jump is |h[i]-h[j]|. Find the minimum total energy lost by the frog to reach stone N.
#include<bits/stdc++.h>
using namespace std;
int n;
int h[100001];
int dp[100001];
int rec(int i){
    // basecase
    if(i==1){
        return 0;
    }
    // cache it
    if(dp[i]!=-1){
        return dp[i];
    }
    // compute
    int ans=1e9;
    ans=min(ans,rec(i-1)+abs(h[i]-h[i-1]));
    if(i>2){
        ans=min(ans,rec(i-2)+abs(h[i]-h[i-2]));
    }
    return dp[i]=ans;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(n)<<endl;
}
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    
    solve();
    
    

}