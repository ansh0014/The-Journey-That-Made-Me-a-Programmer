#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        long long m;
        cin>>n>>m;
        vector<long long> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        bool possible=true;
        long long len=1;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]){
                len++;
        }else{
            if(len>=m){
                possible=false;
            }
            len=1;
        }
    }
    if(len>=m){
        possible=false;
    }
    cout<<(possible?"YES":"NO")<<"\n";
}
return 0;
}