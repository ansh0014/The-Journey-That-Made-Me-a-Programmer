#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    cin>>n;
    vector<long long> a(n);
    vector<long long> b(n);
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    for(long long i=0;i<n;i++){
        cin>>b[i];
    }
    vector<long long> longest_subarray_a(2*n+1,0);
    vector<long long> longest_subarray_b(2*n+1,0);
    long long count=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            count++;
        }else{
            longest_subarray_a[a[i-1]] = max(longest_subarray_a[a[i-1]],count);
            count=1;
        }
    }
    longest_subarray_a[a[n-1]] = max(longest_subarray_a[a[n-1]],count);
    count=1;
    for(int i=1;i<n;i++){
        if(b[i]==b[i-1]){
            count++;
        }else{
            longest_subarray_b[b[i-1]] = max(longest_subarray_b[b[i-1]],count);
            count=1;
        }
    }
    longest_subarray_b[b[n-1]] = max(longest_subarray_b[b[n-1]],count);
    long long max_freq=-1;
    for(int i=1;i<=2*n;i++){
        max_freq = max(max_freq,longest_subarray_a[i]+longest_subarray_b[i]);
    }
    cout<<max_freq<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}