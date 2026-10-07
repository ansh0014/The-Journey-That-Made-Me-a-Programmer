// now i am doing the circle and rectangle overlapping 
// we have given a circle and a rectangle and we have to check whether they are overlapping or not
/*
You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.
*/
// we used the formula of distance between two points and the formula of circle to check whether the circle and rectangle are overlapping or not
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
  int closestx = max(x1, min(xCenter, x2));
  int closesty = max(y1, min(yCenter, y2));
  int dx = closestx - xCenter;
  int dy = closesty - yCenter;
  int ans= dx * dx + dy * dy;
    return ans <= radius * radius;
    if(ans <= radius * radius){
        return true;
    }
    else{
        return false;
    }


    }
};