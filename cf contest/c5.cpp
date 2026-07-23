// now we are doing the codeforeces contest
// now i am doing the farmpiggie and subset sum
// for a permutation * p of even length you can do the following process:
// initialize a counter c=0;
// for each i from 1 to n either add i . pi to ci substract i. pi from c1 or do nothing 
// cfinal submission xi

#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
cin>>n;
    int even =2;
    int odd =1;
    for(int i=1;i<=n;i++){
        if(i&1){
            cout<<even<<" ";
            even+=2;
        }else{
            cout<<odd<<" ";
            odd+=2;
        }
    }
cout<<'\n';

}
int main(){
    // // we make the input and output faster
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}