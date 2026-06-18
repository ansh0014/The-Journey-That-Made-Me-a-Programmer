#include<iostream>
using namespace std;
long long rec(int pos,int tight,int extraState){
    if(pos == 0) return 1;
    if(dp already computed) return dp;
    int limit = tight ? num[pos]-'0':9;
    long long ans=0;
    for(int dig=0;digit<=limit;digit++){
        int newTight = (tight && dig==limit) ? 1:0;
        int newExtraState = extraState + (dig==0);
        ans+=rec(pos-1,newTight,newExtraState);
    }
    return ans;
}