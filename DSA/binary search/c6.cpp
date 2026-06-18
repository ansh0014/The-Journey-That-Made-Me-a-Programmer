// now i am doing the heaters question
// i understadn i have give the postion of heaters and position of house
// i have to find the minimum radius of heaters to cover all the house
// for we use the binary search approach
// the bianrsy serch is used to find the nearest heater for each house and then we can find the maximum distance between the house and the nearest heater
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
      
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        for (int house : houses)
        {
                int leftdist = INT_MAX;
            int rightdist = INT_MAX;
            int index = lower_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
          
            if (index > 0)
            {
                leftdist = house - heaters[index - 1];
            }
            if (index < heaters.size())
            {
                rightdist = heaters[index] - house;
            }
               int nearest = min(leftdist, rightdist);
        radius = max(radius, nearest);
        }
     
        return radius;
    }
};
