#include<bits/stdc++.h>
using namespace std;
void solve(){
long long n;
cin>>n;
vector<long long> second_elements;
long long lowest_first_minimum=INT_MAX;
for(int i=0;i<n;i++){
    long long m;
    cin>>m;
    vector<long long> a(m);
    for(auto &x : a){
        cin>>x;
    }
    sort(a.begin(), a.end());
    second_elements.push_back(a[1]);
    lowest_first_minimum = min(lowest_first_minimum, a[0]);
}
sort(second_elements.begin(), second_elements.end());
long long sum_of_second_elements=accumulate(second_elements.begin(), second_elements.end(), 0LL);
long long lowest_second_minimum=second_elements[0];
long long ans = sum_of_second_elements - lowest_second_minimum + lowest_first_minimum;
cout<<ans<<endl;

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