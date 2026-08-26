// now i am doing the Traingle
// i have given rraingle array, return the minimum path sum from to bootom
//  for each step i my mot to adjacent numbe rof row below . More formally if you are on index i on the current ow i my move to either index i or index i+1 on the next roq
// lets usnderstand the question with example
// approach i used iteration method solve find the minimum from each row and add it to the next row and so on until we reach the bottom of the triangle
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minimumTotal(vector<vector<int>>& triangle){
        int n=triangle.size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
