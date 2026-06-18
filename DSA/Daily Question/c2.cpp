// now i am doing the early finish for land and water Rides 11
// i think this is dp problem because we have compute the answer for each level and store it in dp array
// land rides
/* landStartTime[i] the earlies tiem ith last ride can be boarded
landDuration[i] the time taken to complete the ith land ride
waterStartTime[i] the earliest time the ith water ride can be boarded
waterDuration[i] the time taken to complete the ith water ride
constraints touris must experaicae exacyly one land and one water ride
ride my be stared at its opening tiem or any late momeng
if ride is started at tiem t it fintishes at time t+duration
Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens
i have to return earlies possible tieme at which the toruist can finish both rides
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int calc(vector<int> &start1,
             vector<int> &dur1,
             vector<int> &start2,
             vector<int> &dur2)
    {
        int minTime = INT_MAX;

        for (int i = 0; i < start1.size(); i++)
        {
            minTime = min(minTime, start1[i] + dur1[i]);
        }

        int ans = INT_MAX;

        for (int i = 0; i < start2.size(); i++)
        {
            ans = min(ans,
                      max(minTime, start2[i]) + dur2[i]);
        }

        return ans;
    }
    int ans = INT_MAX;
    int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
    {
        int landTime = calc(landStartTime, landDuration, waterStartTime, waterDuration);
        int waterTime = calc(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(landTime, waterTime);
    }
};
