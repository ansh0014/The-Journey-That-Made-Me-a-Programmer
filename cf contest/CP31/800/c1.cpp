#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,x;
    cin>>n>>x;
    vector<long long> a;
    a.push_back(0);
for(int i=0;i<n;i++){
    long long temp;
    cin>>temp;
    a.push_back(temp);
}
a.push_back(x);
n=a.size();
long long max_distance=INT_MIN;
for(int i=1;i<n;i++){
    if(i==n-1)
        max_distance=max(max_distance,2*(a[i]-a[i-1]));
    else
        max_distance=max(max_distance,a[i]-a[i-1]);
}
cout<<max_distance<<"\n";


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