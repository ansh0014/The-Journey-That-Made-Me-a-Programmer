// right now i am doing the total waviness of number in Range 1
// i have given two intergres num1 and num2
// a digit is a peak if it is greater than its adjacent digits and a digit is a valley if it is less than its adjacent digits
// the first and last digits of a number cannot be peaks or valleys
// any number with fewer than 3 digits has a waviness of 0
// retrun summ of waviness of all numbers in the range [num1,num2]
// lets think about the approach to solve this problem
// we can iterate through all the numbers in the range and calculate the waviness of each number and add it to the answer
// but this approach will be very time consuming because we have to iterate through all the numbers in the range and calculate the waviness of each number
// we can use the string representation of the number to calculate the waviness of each number in the range
// #include <bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
//     int totalWaviness(int num1,int num2){
//         int ans=0;
//         for(int i=num1;i<=num2;i++){
//             string s=to_string(i);
//             int n=s.size();
//             if(n<3) continue;
//             for(int j=1;j<n-1;j++){
//                 if((s[j]>s[j-1] && s[j]>s[j+1]) || (s[j]<s[j-1] && s[j]<s[j+1])){
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };
// now i am doing the Total Waviness of Number in Range 2
// in this problem we have to find the total waviness of number in range [num1, num2]
// in this we have to calculate the waviness of each number in the range and sum it up
// constraints are high so we have to optimize our approach
// we can use dp digit to solve this problem
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string s;

    pair<long long, long long> dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    pair<long long, long long> dfs(
        int pos,
        int prev1,
        int prev2,
        bool tight,
        bool started)
    {
        if (pos == s.size())
        {
            return {1, 0};
        }

        if (!tight && vis[pos][prev1][prev2][started][0])
        {
            return dp[pos][prev1][prev2][started][0];
        }

        int limit = tight ? s[pos] - '0' : 9;

        pair<long long, long long> ans = {0, 0};

        for (int digit = 0; digit <= limit; digit++)
        {

            bool newTight = tight && (digit == limit);

            if (!started && digit == 0)
            {

                auto child = dfs(
                    pos + 1,
                    10,
                    10,
                    newTight,
                    false);

                ans.first += child.first;
                ans.second += child.second;
            }
            else if (!started)
            {

                auto child = dfs(
                    pos + 1,
                    10,
                    digit,
                    newTight,
                    true);

                ans.first += child.first;
                ans.second += child.second;
            }
            else
            {

                int add = 0;

                if (prev1 != 10)
                {
                    if ((prev1 < prev2 && prev2 > digit) ||
                        (prev1 > prev2 && prev2 < digit))
                    {
                        add = 1;
                    }
                }

                auto child = dfs(
                    pos + 1,
                    prev2,
                    digit,
                    newTight,
                    true);

                ans.first += child.first;
                ans.second += child.second + 1LL * add * child.first;
            }
        }

        if (!tight)
        {
            vis[pos][prev1][prev2][started][0] = true;
            dp[pos][prev1][prev2][started][0] = ans;
        }

        return ans;
    }

    long long solve(long long n)
    {
        if (n <= 0)
            return 0;

        s = to_string(n);

        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, true, false).second;
    }

    long long totalWaviness(long long num1, long long num2)
    {
        return solve(num2) - solve(num1 - 1);
    }
};