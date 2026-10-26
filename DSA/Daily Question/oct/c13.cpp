// now i am doing the substring with concatenation of all words
// i have given a string s and an array of strings words. All the strings words are of the same length.
// A concatenated substring is a string that exactly contains all the strings of any permutation of wrods concatenated.
// return the any array of the staring indices of all concatenated substings in s. i can return the answer in any order.
// we used the sliding window approach 
// so we have left pointer and right pointer and we will keep moving the right pointer and we will check if the substring from left to right is a concatenated substring or not. if it is a concatenated substring then we will add the left pointer to the answer and we will move the left pointer to the right. if it is not a concatenated substring then we will move the left pointer to the right until we find a concatenated substring.
// we have use unordered map to keep track of the count of words in the words array and we will use another unordered map to keep track of the count of words in the current substring from left to right. if the count of words in the current substring is equal to the count of words in the words array then we have found a concatenated substring.
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
vector<int> ans;
int n=s.size();
int m=words.size();
if(m==0) return ans;
unordered_map<string,int> mp;
int wl=words[0].size();
int totalen=m*wl;
if(n<totalen) return ans;
for(const string &word:words) mp[word]++;
for(int i=0;i<wl;i++){
    unordered_map<string,int> mp2;
    int left=i;
    int count=0;
    for(int right=i;right+wl<=n;right+=wl){
        string word=s.substr(right,wl);
        if(mp.find(word)==mp.end()){
            mp2.clear();
        count=0;
        left=right+wl;
        continue;
    }
          
    mp2[word]++;
    count++;
    while(mp2[word]>mp[word]){
        string leftword=s.substr(left,wl);
        mp2[leftword]--;
        count--;
        left+=wl;
    }
    if(count==m){ ans.push_back(left);
    string leftword=s.substr(left,wl);
    mp2[leftword]--;
    count--;
    left+=wl;
    }
}

}
return ans;
}

};