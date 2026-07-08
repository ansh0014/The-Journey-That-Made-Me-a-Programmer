// now i am doing the minimum swaps to make the strings equal
// i have given two strings s1 and s2 of equal length consisting letters "x"and "y" only. my task is to make these two strins equal to each . i can swap any two characters that belong different strings, which means swap s1[i] and s2[j]
// return the minimum number os swaps required to make s1 and s2 equal or return -1 if its is impossible to do so.
// approach i have to used greedy we have swap 
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int minimumSwap(string s1,string s2){
        int n=s1.size();
        int xy=0,yx=0;
        for(int i=0;i<n;i++){
            if(s1[i]=='x' && s2[i]=='y'){
                xy++;
            }else if(s1[i]=='y' && s2[i]=='x'){
                yx++;
            }
        }
      if(xy%2!=yx%2) return -1;
        return xy/2 + yx/2 + (xy%2)*2;
    }
};