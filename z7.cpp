// now i am doing the restore the ip addresses
// i understand i have check the valid ip addresses
// i have given a string s containing only digits return all possible valid ip addresses that can be formed by inserting dots into s. you are not allowed to reorder or remove any digits in s. you may return the valid ip addresses in any order.
// think i used to check it using the backtracking
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int backtrack(string s, int start, int dots, string current, vector<string>& res) {
        int dots = 0;
        if (dots == 4 && start == s.size()) {
            res.push_back(current.substr(0, current.size() - 1)); // Remove the last dot
            return 1;
        }
        if (dots > 4) return 0;
        int count=0;
    while (start < s.size() && dots < 4) {
        for (int len = 1; len <= 3 && start + len <= s.size(); ++len) {
            string part = s.substr(start, len);
            if ((part[0] == '0' && part.size() > 1) || stoi(part) > 255) continue;
            count += backtrack(s, start + len, dots + 1, current + part + ".", res);
        }
        break; 
    }
    return count;
}
        vector<string> restoreIpAddresses(string s) {
  vector<string> res;
  string current;
  backtrack(s, 0, 0, current, res);
  return res;      
    }
};