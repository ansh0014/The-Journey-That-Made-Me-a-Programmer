// now i  am doing the word break 
// i have given a string s and a dictionary of string wordDict, return true if s can semented into space-sperated squence of one or more dictionary words
// smae word in the dictionary may be reused multiple times in the segmentation
// approach we used the dp + unordered set to store the words in the dictionary and then we will use dp to check if the string can be segmented or not
#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
	   bool wordBreak(string s, vector<string>& wordDict) {
     int n = s.size();
	 unordered_set<string> st(wordDict.begin(), wordDict.end());
unordered_map<int,bool> dp;
dp[0] = true;
for(int i=1; i<=n;i++){
	
	for(int j=0;j<i;j++){
		if(dp[j] && st.find(s.substr(j,i-j))!=st.end()){
			dp[i] = true;
			break;
		}
	}
	if(dp.find(i)==dp.end()){
		dp[i] = false;
	}
	else{
		dp[i] = true;
	}
	
}
return dp[n];
    }
};