// now i am doing the largest rectangle in histogram
// i have given an array of integes heights representign the histogram's bar height where the width of each bar is 1. return the area of largest rectangle in the histogram.
// we can do same question with the two pointer or siding window
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int largestRectangleArea(vector<int>& heights){
  int left=0;
  int n=heights.size();
  int right=n-1;
  int maxArea=0;
    while(left<=right){
        int height=min(heights[left],heights[right]);
        int width=right-left+1;
        maxArea=max(maxArea,height*width);
        if(heights[left]<heights[right]){
            left++;
        }else{
            right--;
        }
     
    }
       return maxArea;
}
};