#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<long long> a(n);
        vector<long long> b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        const long long INF = 1e9 + 7;
        // first is no rearrangement
        long long cost1 = 0;
        bool ok1 = true;
        for(int i=0;i<n;i++){
            if(a[i] < b[i]){
                ok1 = false;
                break;
            }
            cost1 += (a[i] - b[i]) ;
        }
    // now rearrangement once
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    long long cost2 = c;
    bool ok2 = true;
        for(int i=0;i<n;i++){
            if(a[i] < b[i]){
                ok2 = false;
                break;
            }
            cost2 += (a[i] - b[i]) ;
        }
        if(!ok1 && !ok2){
            cout<<-1<<"\n";
        }
        else if(ok1 && ok2){
            cout<<min(cost1,cost2)<<"\n";
        }
        else if(ok1){
            cout<<cost1<<"\n";
        }
        else{
            cout<<cost2<<"\n";
        }
    }

    return 0;
    
}