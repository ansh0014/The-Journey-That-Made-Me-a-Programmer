// now we are doing the queen problem
#include<bits/stdc++.h>
using namespace std;
int n;
int queen[10]; // queen[i] where is my queen in row i
bool check(int row,int col){
    for(int i=0;i<row;i++){
        int prow=i;
        int pcol=queen[i];
        if(pcol==col||abs(pcol-col)==abs(prow-row)) return 0;
    }
    return 1;
}

int rec(int level){ // rec->number of ways to populate [level---n-1] rows for a valid configuration
// level-> row in which we are placing the queen
// pruning code
// basecase
if(level==n) return 1;
 
// compute
int ans=0;
// we loop over all choices
for(int col=0;col<n;col++){
    if(check(level,col)){
        // place queen
        queen[level]=col; // move place
        // explore option
        ans+=rec(level+1); // move next level
        // if i already have the answer then i can return it
        // reverte back means backtrack
        queen[level]=-1; // backtrack
    }
}
// return
return ans;
}
void solve(){
cin>>n;
memset(queen,-1,sizeof(queen));
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