// now i am doing the Vacation question
// toro summer vacation starts tomorrow he decided to make the plans for it now 
// the vacation consits of N day for (each i(1<=i<=n))
#include<bits/stdc++.h>
using namespace std;
int n;
int a[100001][3];
int dp[100005][4];
int rec(int day,int last){
    if(day==n) return 0;
    if(dp[day][last]!=-1){
        return dp[day][last];
    }
    int ans=0;
    for(int activity=0;activity<3;activity++){
        if(activity!=last){
            ans=max(ans,a[day][activity]+rec(day+1,activity));
        }
    }
    return dp[day][last]=ans;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,3)<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}