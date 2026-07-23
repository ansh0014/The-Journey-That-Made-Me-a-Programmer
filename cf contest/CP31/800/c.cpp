#include<bits/stdc++.h>
using namespace std;
void solve(){
long long n,k;
cin>>n>>k;
vector<long long> a(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
vector<long long> cpy=a;
sort(cpy.begin(),cpy.end());
if(cpy==a || k>1){
    cout<<"YES\n";
}
else{
    cout<<"NO\n";
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