// ṇow i am doing the minimum cost to convert string 111
// i have given two srtings source and target.
// i have also given 2d string array rules, where rules[i]=[pattern, replacement] and an integer array costs, where costs[i] is base cost of applying rules[i]. both array shave the same length additionaly patterni and replacementi have the same lenght
// rules:
// choose an index l such that range of postions from l to l+patterni.length-1 exists in the current string and non of these postions has been used in previous rule application.
// for each index j the character patterni[j] must either be equal to the current chracter at psition l+j or be'*".
// replace the charactes this range with replacement i the replacement is used exactly as given and does not coantin wildcards
// the cost of this rule application is costs[i] plus the  number of "*" characters in patterni
// once a character position has been used in rule application it cannot be used in any later rule application.
// since every patterni and replacementi have the same lenght character position are preserved after every rule application.
// return the minimum total cost require to reansform soruce into target . if it is impossible return -1.

// let's write the code 
// dp work we used take it or not take approach for that
// transition will be if we take the rule then we will add the cost of that rule and also the number of * in the pattern and also we will mark the positions as used and then we will move to the next position and if we don't take the rule then we will just move to the next position
// state is defined by the current position in the source string and the current state of the used positions. We can represent the used positions as a bitmask, where each bit corresponds to a position in the source string. If a bit is set to 1, it means that position has been used in a previous rule application.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minCost(
        string source,
        string target,
        vector<vector<string>>& rules,
        vector<int>& costs
    ) {

        int n = source.size();

        const long long INF = 1e18;

        vector<long long> dp(n + 1, INF);


        dp[n] = 0;


        for (int pos = n - 1; pos >= 0; pos--) {

  
            if (source[pos] == target[pos]) {
                dp[pos] = dp[pos + 1];
            }

            for (int i = 0; i < rules.size(); i++) {

                string pattern = rules[i][0];
                string replacement = rules[i][1];

                int m = pattern.size();

                if (pos + m > n)
                    continue;

                bool canApply = true;
                int wild = 0;

                for (int j = 0; j < m; j++) {

                    if (pattern[j] != '*' &&
                        pattern[j] != source[pos + j]) {

                        canApply = false;
                        break;
                        }
                    if (replacement[j] != target[pos + j]) {

                        canApply = false;
                        break;
                    }

                    if (pattern[j] == '*')
                        wild++;
                }

                if (!canApply)
                    continue;

                long long ruleCost =
                    costs[i] + wild;

                if (dp[pos + m] != INF) {

                    dp[pos] = min(
                        dp[pos],
                        ruleCost + dp[pos + m]
                    );
                }
            }
        }

        return dp[0] == INF ? -1 : (int)dp[0];
    }
};
    

