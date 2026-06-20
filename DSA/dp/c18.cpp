// now i am doing the A and B pile problem
// first we do the recursive way then we move to iterative way
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001]
int rec(int x, int y){
// puring 
//  base case
if(x==0&&y==0) return 0;

// cache check
if(dp[x][y]!=-1) return dp[x][y];
// compute
int ans=0;
for(int z=0;z<x;z++){
    if(rec(z,y)==0){
        ans=1;
        break;
    }
}
for(int z=0;z<y;z++){
    if(rec(z,x)==0){
        ans=1;
        break;
    }
}
for(int z=1;z<min(x,y);z++){
    if(rec(x-z,y-z)==0){
        ans=1;
        break;
    }
}
// save and return
return dp[x][y]=ans;
}
void solve(){
int a,b;
cin>>a>>b;
// memset(dp,-1,sizeof(dp));
// we are looping over states and computing the answer for each state using the smaller states
for(int x=0;x<=a;x++){
    for(int y=0;y<=b;y++){
        if(x==0&&y==0) dp[x][y]=0;
        else{
            int ans=0;
            for(int z=0;z<x;z++){
                if(dp[z][y]==0){
                    ans=1;
                    break;
                }
            }
            for(int z=0;z<y;z++){
                if(dp[z][x]==0){
                    ans=1;
                    break;
                }
            }
            for(int z=1;z<min(x,y);z++){
                if(dp[x-z][y-z]==0){
                    ans=1;
                    break;
                }
            }
            dp[x][y]=ans;
        }
    }
}
cout<<dp[a][b]<<endl;
}
int main(){
    ios_base::sync_with_studio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    for(int i=0;i<t;i++){
        solve();
    }
}

