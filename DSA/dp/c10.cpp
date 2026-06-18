// now i am doing the frog jump
// i have given a set of stones poistion in units in sorted ascending order, determine if the frog can corss the river by landing on the last stone. Initially the frog is on the first stone and assumes the first jump must be 1 unit.
// if the frog last was k units its next jump must be either k-1, k, or k+1 units. the frog can only jump in the forward direction.
// this is dp problem first form take or not take form
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
int rec(vector<int> &stones,unordered_map<int,int>&pos,int i,int k){
 if(i==stones.size()-1) return true;
 for(int jump = k-1;jump<=k+1;jump++){
     if(jump>0 && pos.count(stones[i]+jump)){
         if(rec(stones,pos,pos[stones[i]+jump],jump)) return true;
     }
 }
    return false;

}
bool canCross(vector<int> &stones){
    unordered_map<int,int>pos;
    for(int i=0;i<stones.size();i++){
        pos[stones[i]]=i;
    }
    return rec(stones,pos,0,0);
}

};