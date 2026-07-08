// now we are doing the substring
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// string t="0100";
// int dp[1000100][16];
// int rec(int level,int latthree){
// if(level==n) return 1;;
// if(dp[level][latthree]!=-1) return dp[level][latthree];
// if(lastthree==2){
//     //010
//     int ans=rec(level+1,5);

// }else{
//     ans=rec(level+1, (lastthree<<1|0) & 7)+rec(level+1, (lastthree<<1|1) & 7);
//     ans+=rec(level+1, (lastthree<<1|0) & 7)+rec(level+1, (lastthree<<1|1) & 7);

// }
// return dp[level][lastthree]=ans;
// }

// void solve() {
//     cin>>n;
//     cout<<rec(0,0)<<endl;
// }
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t=1;
//     for(int i=0;i<t;i++){
//         solve();
//     }
// }
// now we are doing the same subtsring question using the logic of the state machine
#include<bits/stdc++.h>
using namespace std;
int n;

int dp[1000100][5];
using namespace std;
int rec(int level,int match){
if(match==4) return 0;
if(level==n) return 1;
if(dp[level][match]!=-1) return dp[level][match];
int ans=0;
if(match==0){
    ans=rec(level+1,0)+rec(level+1,1);
}else if(match==1){
    ans=rec(level+1,2)+rec(level+1,1);
}else if(match==2){
    ans=rec(level+1,3)+rec(level+1,2);
}else if(match==3){
    ans=rec(level+1,4)+rec(level+1,3);
}

return dp[level][match]=ans;
}
void solve(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
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