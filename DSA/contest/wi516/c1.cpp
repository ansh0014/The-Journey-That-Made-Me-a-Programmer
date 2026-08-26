// now i am doing the find all number disappeared in an array 11
// i have given an integer array nums and two integers lower and upper
// missing integer is integer in incluse range [lower, upper ] that does not appear in nums
// return the 2d integer array where each element is of the form [start, end] represeting contigouurs range of missing integers. return the ranes in incrasein order . if ther are no missiin integer ruten any emtpy
// approach we used set to store the numbers and then used the condition to check the missing numbers and then used the loop to find the ranges
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findDisappearedNumbers(
        vector<int> &nums,
        int lower,
        int upper)
    {

        set<int> s(nums.begin(), nums.end());

        vector<vector<int>> res;

        int start = -1;

        for (int i = lower; i <= upper; i++)
        {
            if (s.find(i) == s.end())
            {

                if (start == -1)
                {
                    start = i;
                }
            }
            else
            {

                if (start != -1)
                {
                    res.push_back({start, i - 1});
                    start = -1;
                }
            }
        }
        if (start != -1)
        {
            res.push_back({start, upper});
        }

        return res;
    }
};