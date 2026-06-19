// Find the number of N length BInary strings that doesn't conatins 0100
#include<bits/stdc++.h>
using namespace std;
int n;
string t="0100";
int dp[1000001][5];
int rec(int level,int match){
// puring 
if(match==4) return 0;
// basecase
if(level==n) return 1;
if(dp[level][match]!=-1) return dp[level][match];
// compute
int ans=0;
ans=rec(level+1,match+1)+rec(level+1,match);

// save and compute
return dp[level][match]=ans;
}
void solve() {
    cin>>n;
    cout<<rec(0,0)<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    for(int i=0;i<t;i++){
        solve();
    }
}