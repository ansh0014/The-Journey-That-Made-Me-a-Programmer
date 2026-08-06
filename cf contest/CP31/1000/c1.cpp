// now i am doing the swap and delete
// i have given an binary string s(a string consisting only of 0-s and 1-s)
// i can perform two type operations on s:
// delete any character from s.this operation costs 1 coin
// swap any two adjacent characters in s.this operation costs 0 coin free
// i can perform these operation any number of time and in any order
#include<bits/stdc++.h>
using namespace std;
void solve(){
string s;
cin>>s;
int n=s.size();
int count_0=0,count_1=0;
for(int i=0;i<n;i++){
    if(s[i]=='0') count_0++;
    else count_1++;
}
int len=0;
for(int i=0;i<n;i++){
    if(s[i]=='0' && count_1>0){
        count_1--;
        len++;
    }
    
    else if(s[i]=='1' && count_0>0){
        count_0--;
        len++;
    }else{
        break;
    }
}
cout<<n-len<<"\n";
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