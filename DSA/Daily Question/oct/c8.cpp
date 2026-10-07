// now i am doing the remove all occurrences of substring
// we have given two strings s and part, perform the follwing operation on s untill all occurrence of the substring part are removed
// find the leftmost occurrence of part and remove it from s
// first i have thing we put string in stack then in loop i will match the condition with part and if it is true i will store the index of the part in stack and then i will pop the part from stack and then at the end i will return the string from stack
// we stroing final we make vector of string
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOccurrences(string s, string part) {
  stack<char>st;
  int n = s.size();
  int m = part.size();
  vector<char>ans;
while(!st.empty()) st.pop();
for(int i=0;i<n;i++){
    st.push(s[i]);
    if(st.size()>=m){
        bool flag = true;
        for(int j=0;j<m;j++){
            if(st.top()!=part[m-1-j]){
                flag=false;
                break;
            }
            st.pop();
        }
        if(!flag){
            for(int j=0;j<m;j++){
                st.push(part[j]);
            }
        }
    }
   
}
reverse(ans.begin(),ans.end());
while(!st.empty()){
    ans.push_back(st.top());
    st.pop();
}
return string(ans.begin(),ans.end());
   
    }
};