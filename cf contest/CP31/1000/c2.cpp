// now i am doing the paspberries
// i have given an array of integers a1, a2,.... an and number k(2<=k<=5). In one operation , you can do the following.
// choose any index 1<=i<=n and set ai=ai+1
// we have find the minimum number of operations needed to make hte product of all numbers in the array an divisible by k.
#include<bits/stdc++.h>
using namespace std;
void solve(){
int a,k;
cin>>a;
cin>>k;
vector<int> arr(a);
for(int i=0;i<a;i++){
    cin>>arr[i];
}
long long ans=INT_MAX;
long long even=0;
for(int i=0;i<a;i++){
    if(arr[i]%2==0){
        even++;
    }
    if(arr[i]%k==0){
        ans=0;
    }
ans = min(ans, 1LL * ((k - arr[i] % k) % k));

}
if(k==4){
    if(even>=2){
    ans=min(ans,0LL);
    }else if (even==1){
        ans=min(ans,1LL);
    }else if(even==0){
        ans=min(ans,2LL);
    }
  
}
  cout<<ans<<"\n";
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