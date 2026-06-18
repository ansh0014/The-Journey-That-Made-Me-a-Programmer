// now we are doin the B-frog 2
// if the frog i currently on stoen i , jump to one of the following : stone i+1, i+2,...i+k here a cost of abs[hi-hj] is incurred , where j is the stoen to land on
// find the minimum possible toatl cost incurred befre the frog reaches Stone N.
// All values in input are integers.
// 2≤N≤10e5
//  1<=k<=100
// 1<hi<=10e4
#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int h[100001];

int dp[100001];
int rec(int i){
    if(i==1){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int ans=1e9;

    for(int j=1;j<=k;j++){
        if(i-j>=1){
            ans=min(ans,rec(i-j)+abs(h[i]-h[i-j]));
        }
    }
    dp[i]=ans;
    return ans;
}

void solve(){
    cin>>n>>k;
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
