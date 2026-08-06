// their are n teams in a football tournament. Each team match up once after every match, pak chanek receives two integers as the result of the match the numbers of goals the two teams score during the match the efficiency of a team is equal to the total number of goals the team scores in each of its matches minus the total number of goals scored by the opponent in each of it matches


#include<bits/stdc++.h>
using namespace std;
void solve(){
long long n;
cin>>n;
vector<long long> a(n);
for(long long i=0;i<n-1;i++){
    cin>>a[i];
}
long long sum=0;
for(long long i=0;i<n-1;i++){
    sum+=a[i];
    
}
cout<<-1*sum<<endl;


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