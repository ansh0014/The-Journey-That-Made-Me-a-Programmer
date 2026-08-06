// i have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planeted in adjacent plots.
// i have given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty and an integer n, return true if n nfew flowers can be planted in the flowerbed without violating the no-adjacet-flwoers rule and false otherwise.
// approach we used greedy
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        int m=flowerbed.size();
        for(int i=0;i<m;i++){
            if(flowerbed[i]==0){
                if((i==0 || flowerbed[i-1]==0) && (i==m-1 || flowerbed[i+1]==0)){
                    flowerbed[i]=1;
                    count++;
                }
            }
        }
        return count>=n;
    }
};