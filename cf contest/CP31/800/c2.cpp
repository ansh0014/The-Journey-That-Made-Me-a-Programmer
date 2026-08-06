// now i am doing the cover in water codeforces problem
#include<bits/stdc++.h>
using namespace std;
void solve(){
int n;
    cin>>n;
    string s;
    cin>>s;
    bool three_empty_cell=false;
    int total_count_empty=0;
    for(int i=0;i<n;i++){
        if(s[i]=='.'&& i+1<n && s[i+1]=='.' && i+2<n && s[i+2]=='.'){

            three_empty_cell=true;
            break;
        }
        if(s[i]=='.'){
            total_count_empty++;
        }
    }
        if(three_empty_cell){
            cout<<2<<"\n";
        }else{
            cout<<total_count_empty<<"\n";
        }
}


int main(){
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin>>t;
 while(t--){
    solve();
 }
 return 0;
}