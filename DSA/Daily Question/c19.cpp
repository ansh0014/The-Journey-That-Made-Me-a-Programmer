// now we are doing the Maximum building height
// i want to build n new building in a city . the new buildings will be built in a line and labeled from 1 to n.
// However , there are city restriction on the heights of the new buildings.
// 1 the height of each building must be a non-negative integer.
// the height of the first building must be 0
// the height difference between any two adjacent buildings cannot exceed 1.
// i have also given a 2d integer array restrictions where restrictions[i]=[idi, maxHeighti] indicates that the building with the label idi must have a height less than or equal to maxHeighti.
// return the maximum possible height of the tallest building.
// approach i have to find the maximum possible height of the tallest building that can be built in the city while satisfying the given restrictions. I will use a greedy approach to determine the heights of the buildings based on the restrictions and the constraints provided.
// i have to sort the restrictions array based on the building labels to ensure that we process the buildings in order. Then, I will iterate through the buildings and calculate the maximum possible height for each building while considering the restrictions and the height difference constraint. Finally, I will return the maximum height among all buildings.
#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        restrictions.push_back({1,0});

        bool found = false;

        for(auto &r : restrictions)
        {
            if(r[0] == n)
            {
                found = true;
                break;
            }
        }

        if(!found)
            restrictions.push_back({n,n-1});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        for(int i=1;i<m;i++)
        {
            restrictions[i][1] =
                min(restrictions[i][1],
                    restrictions[i-1][1] +
                    restrictions[i][0] -
                    restrictions[i-1][0]);
        }

   
        for(int i=m-2;i>=0;i--)
        {
            restrictions[i][1] =
                min(restrictions[i][1],
                    restrictions[i+1][1] +
                    restrictions[i+1][0] -
                    restrictions[i][0]);
        }

        int ans = 0;

        for(int i=1;i<m;i++)
        {
            long long id1 = restrictions[i-1][0];
            long long h1  = restrictions[i-1][1];

            long long id2 = restrictions[i][0];
            long long h2  = restrictions[i][1];

            long long dist = id2 - id1;

            ans = max(ans,
                      (int)((h1 + h2 + dist) / 2));
        }

        return ans;
    }
};