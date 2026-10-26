#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long>a(n);
        for(auto &x:a) cin>>x;
        long long ans=0;
        while(true){
            long long mx=*max_element(a.begin(),a.end());
            long long mi=*min_element(a.begin(),a.end());
            if(mx==mi){
                ans+=mx;
                break;
            }

            int k=63-__builtin_clzll(mx);
            long long p=1LL<<k;
            if(mi<p){
ans+=(p<<1)-1;
break;
}
for(auto &x:a){
    x-=p;
    
}
ans+=p;
            }
            cout<<ans<<endl;

        }
        return 0;

    }

