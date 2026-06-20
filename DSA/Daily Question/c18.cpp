// The Find The Highest Altitude Problem

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int largestAltitude(vector<int>& gain){
        int maxAltitude = 0;
        int currentAltitude = 0;
        int n=gain.size();
        for(int i=0;i<n;i++){
            currentAltitude += gain[i];
            maxAltitude = max(maxAltitude, currentAltitude);
        }
        return maxAltitude;
        
    }
}