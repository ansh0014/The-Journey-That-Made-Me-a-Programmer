#include<bits/stdc++.h>
using namespace std;
void solve(){
long long  n;
cin>>n;
long long a[n];
for(long long i=0;i<n;i++){
    cin>>a[i];
}
map<long long, long long>mp;
for(long long i=0;i<n;i++){
    mp[a[i]]++;
}
if(mp.size()>=3){
    cout<<"NO"<<endl;

}else{
    long long freq1=mp.begin()->second;
    long long freq2=mp.rbegin()->second;
    if(freq1==freq2){
        cout<<"YES"<<endl;
    }
    else if(n%2==1 && abs(freq1-freq2)==1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}