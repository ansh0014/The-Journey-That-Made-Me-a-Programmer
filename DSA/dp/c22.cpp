#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long dp[n];
    long long ans=0;
    for(int i=0;i<n;i++){
        if(i==0){
            dp[i]=arr[i];
        }
        else{
            dp[i]=max(dp[i-1]+arr[i],arr[i]);
        }
        ans=max(ans,dp[i]);
        
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}