// now i am doing the champagne tower
// we stack glasses in a pyramid where the first row has 1 glass , the second row has 2 glassed and so until 100th row . each glass holds one cup of champagne
// then some chapagne is poured is poured into the first glass at the top. When the topmost glass is full any excess liquid poured will fasll equally to the galss immediately to the left and right of it. When those glasses become full any excess changne will fall equally to the left and right tof those glasses and so on. (a galss at the bottom row has its excess champagne fall on the floor.)
// for example after one cup of champagne is poured, the top most galss is full.
// after two cups of champagne are pured, the two glasses ont the second row are half full. after there cups of champagne are poured, those tow cups become full there are 3 full galsses total now. After four cups of champagne are poured, the third row the middle glass half full and tow outside glasses are quater full as pictured below
// logic we take it and not take appraoch of dp so this question is done with memo
#include<bits/stdc++.h>
using namespace std;
class Solution{
    double dp[101][101];
    public:
    double solve(int poured,int query_row,int query_glass){
    //  first we write the puring
   
    // now the base case 
    // i make simple varible name
    int r=query_row;
    int c=query_glass;
    if(r<0 || c<0 || c>r) return 0.0;
    if(r==0 && c==0) return (double)poured;
   
    // now we cache it 
    if(dp[r][c]!=-1.0) return dp[r][c];
    // now we write the logic
    // now we think r-1 and c-1 is left because the left glass is in the previous row and the left glass is in the previous column and the right glass is in the previous row and the right glass is in the same column
   double left=solve(poured,r-1,c-1);
    double right=solve(poured,r-1,c);
    
    double fromleft=max(0.0,(left-1.0)/2.0);
    double fromright=max(0.0,(right-1.0)/2.0);
    return dp[r][c]=fromleft+fromright;
    
}


        double champagneTower(int poured, int query_row, int query_glass) {
       for(int i=0;i<101;i++){
           for(int j=0;j<101;j++){
               dp[i][j]=-1.0;
           }
        }
        return min(1.0,solve(poured,query_row,query_glass));
    }
};