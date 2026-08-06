#include<bits/stdc++.h>
using namespace std;
void solve(){
long long n;
cin>>n;
if(n%3==0){
    cout<<"Second\n";
}
else{
    cout<<"First\n";
}
}
int main(){
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin>>t;
 while(t--){
    solve();
 }
}