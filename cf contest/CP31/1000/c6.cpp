#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    long long k;
    long long q;
    cin>>n>>k;
    cin>>q;
    vector<long long> a(n);
    for(long long i=0;i<n;i++){
        cin>>a[i];
        a[i]=(a[i]>q)?0:1;
    }
    long long days=0;
    long long ways=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            days++;
        }else{
            if(days>=k){
                long long diff=days-k+1;
                ways+=(diff*(diff+1))/2;
            }
            days=0;
        }
    }
    if(days>=k){
        long long diff=days-k+1;
        ways+=(diff*(diff+1))/2;
    }
    cout << ways << endl;

}
int main(){
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
    
}