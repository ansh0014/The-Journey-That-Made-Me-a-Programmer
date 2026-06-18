// now i am doing the minimum window substring
// i have given two strings s and t of lengths ma nad n return the minimum window substring of s such that every  character in t including duplicates is included in the window. if there is no such substring return the empty srtring "".
// i have to use sliding window approach to solve this problem 
// i have to use on both side
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
string minWindow(string s, string t){
    vector<int> freq(128,0);
    for(char i:t){
        freq[i]++;
    }
    int left=0;
    int count=t.size();
    int minLen=INT_MAX;
    int start=0;
    for(int right=0;right<s.size();right++){
        if(freq[s[right]]>0){
            count--;
        }
        freq[s[right]]--;
        while(count==0){
            if(right-left+1<minLen){
                minLen=right-left+1;
                start=left;
            }
            freq[s[left]]++;
            if(freq[s[left]]>0){
                count++;
            }
            left++;
        }
    }
        if(minLen==INT_MAX){
            return "";
        }
        return s.substr(start,minLen);
    }
    
};
