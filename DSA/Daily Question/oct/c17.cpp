// now i am doing the replace the substring for balanced string

// i have given a string of lenght n containing only four kinds of characters 'Q' , 'W' , 'E' and 'R'. A string is said to be balanced if each of its characters appears n/4 times.
// return the minimum length of the substring that can be replaced with any other string of the same
// we used the two pointer approach to solve this problem. we will keep two pointers left and right and we will keep moving the right pointer until the substring from left to right is balanced. if it is balanced then we will update the answer with the length of the substring and we will move the left pointer to the right until the substring from left to right is not balanced. if it is not balanced then we will move the right pointer to the right until the substring from left to right is balanced. at the end we will return the answer.
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
     int balancedString(string s) {
        int n = s.size();
        unordered_map<char, int> count;
        int left = 0, right = 0;
        int ans = n; 
        for(int i = 0; i < n; i++) {
            count[s[i]]++;
        }
        while(right < n) {
            count[s[right]]--;
            while(left < n && count['Q'] <= n / 4 && count['W'] <= n / 4 && count['E'] <= n / 4 && count['R'] <= n / 4) {
                ans = min(ans, right - left + 1);
                count[s[left]]++;
                left++;
            }
            right++;
        }
        return ans;
    }

};
