// now i am doing the plaindrome pairs
// this is interesting question because i have given the words then i have to mix the words then find the plandromic we have not check we have to print it
// we used hashing offcourse then  we used the slinding window to check teh palindromic
// lest start with the code
// remeber i have to care about the edge case
// #include<iostream>
// #include<string>
// #include<vector>
// #include<unordered_map>
// #include<algorithm>
// #include<set>
// using namespace std;
// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int l = 0;
//         int r = s.size() - 1;
//         while (l < r) {
//             if (s[l] != s[r]) {
//                 return false;
//             }
//             l++;
//             r--;
//         }
//         return true;
//     }
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         unordered_map<string, int> mp;
//         int n = words.size();
//         for (int i = 0; i < n; i++) {
//             string s = words[i];
//             reverse(s.begin(), s.end());
//             mp[s] = i;
//         }
//         set<vector<int>> st;
//         int emptyindex = -1;
//         for (int i = 0; i < n; i++) {
//             if (words[i] == "") {
//                 emptyindex = i;
//                 break;
//             }
//         }
//         if (emptyindex != -1) {
//             for (int i = 0; i < n; i++) {
//                 if (i != emptyindex && isPalindrome(words[i])) {
//                     st.insert({i, emptyindex});
//                     st.insert({emptyindex, i});
//                 }
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             string s = words[i];
//             int m = s.size();
//             for (int j = 0; j <= m; j++) {
//                 string l = s.substr(0, j);
//                 string r = s.substr(j);
//                 if (mp.count(l) && mp[l] != i && isPalindrome(r)) {
//                     st.insert({i, mp[l]});
//                 }
//                 if (j != m && mp.count(r) && mp[r] != i && isPalindrome(l)) {
//                     st.insert({mp[r], i});
//                 }
//             }
//         }
//         vector<vector<int>> ans(st.begin(), st.end());
//         return ans;
//     }
// };
// now we are doing the sum of subarray minimums
// this question is combination of stack and hashing because stack is used for compare the mini and hashing is used for making the subarray and then we will give the sum of the subarray minimums
// we have implement the next smaller element and previous smaller element then we will find the sum of the subarray minimums by using the formula left*right*arr[i] where left is the distance between the current element and the previous smaller element and right is the distance between the current element and the next smaller element and arr[i] is the value of the current element
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution
{
public:
   vector<int> findNSE(vector<int>&arr){
    int n=arr.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        int current =arr[i];
        while(!st.empty()&&arr[st.top()]>=arr[i]){
            st.pop();
        }
        ans[i]=st.empty()?- n:st.top();
        st.push(i);
    }
    return ans;
   }
    vector<int> findPSE(vector<int>&arr){
     int n=arr.size();
     vector<int>ans(n);
     stack<int>st;
     for(int i=0;i<n;i++){
          int current =arr[i];
          while(!st.empty()&&arr[st.top()]>arr[i]){
                st.pop();
          }
          ans[i]=st.empty()?-1:st.top();
          st.push(i);
}
return ans;
    }
    int sumSubarrayMins(vector<int>&arr){
     vector<int>nse=findNSE(arr);
     vector<int>pse=findPSE(arr);
     int n=arr.size();
     long long sum=0;
     for(int i=0;i<n;i++){
        long long left=i-pse[i];
        long long right=nse[i]-i;
        sum=(sum+left*right*arr[i])%1000000007;
     }
     return sum;
    }
};
