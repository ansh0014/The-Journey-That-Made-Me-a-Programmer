// first we do the recurssive approach for solving the staris problem
// i make template
#include<bits/stdc++.h>
using namespace std;
int n;
int rec(int level){ // ret->number of way to N if we are at stair level
    // level-> stair i am at
    // pruning code
     if(level>n) return 0;
    // base case
    // when their is counting problem base case is always zero and 1
    if(level==n) return 1;
    // loop over choice
    int ans=0;
    for(int step=1;step<=3;step++){
        // first we do current move is valid for that we make the check
        if(level+step<=n){
            // if it is valid then we make the move and call the function for next level
           int ways= rec(level+step); //move
           ans+=ways;

        }
    }
    return ans;


 

}
void solve(){
cin>>n;
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