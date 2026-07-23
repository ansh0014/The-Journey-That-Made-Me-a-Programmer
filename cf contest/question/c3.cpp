// now i am doing construct an array
// i have give n intergern i have to construct an array of integer a1,a2,-----an 
// condition
// 1<=ai<=2.n
// all elements of the array ans the sums of adjacent elements are pairwise distince in other words among the numbers{a1,a2,---an,a1+a2,a2+a3,---an-1+an} all numbers are pairwise distinct
#include<iostream>
#include<vector>
#include<functional>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cout << 2 * i + 1;
            if(i+1<n) cout<<" ";
        }
        cout<<"\n";

    }
    return 0;
}