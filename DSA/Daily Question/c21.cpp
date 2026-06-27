// now i am doing the Maximum Number of Ballons
// i have given string text, i want to use the characters of text to form to form as many instances of the word "balloon" as possible
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxNumberOfBalloons(string text){
        vector<int> freq(26,0);
        for(char c:text){
            freq[c-'a']++;
        }
        int ans=INT_MAX;
        ans=min(ans,freq['b'-'a']);
        ans=min(ans,freq['a'-'a']);
        ans=min(ans,freq['l'-'a']/2);
        ans=min(ans,freq['o'-'a']/2);
        ans=min(ans,freq['n'-'a']);
        return ans;
    }
};