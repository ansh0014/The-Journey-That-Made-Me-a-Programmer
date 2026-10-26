#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string k;
        cin>>n;
        cin>>k;
     int s=count(k.begin(),k.end(),'1');
     if(s==0) cout<<0<<endl;
     else if(s==2) cout<<1<<endl;
     else cout<<(int)(k.rfind('1')-k.find('1'))<<endl;
    }
    return 0;
}