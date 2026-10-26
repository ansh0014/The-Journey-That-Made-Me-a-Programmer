// right now i am doing the minimum insertations ot balance a prentheses string
// given a parentehese string s containg only the characters '(' and ')'. A parentheses sting is balanced if
// any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))' and every right parenthesis must have a corresponding left parenthesis '('.
// left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
// approach we used stack to keep track of the left parenthesis and right parenthesis. we will iterate through the string and for every left parenthesis we will push it into the stack and for every right parenthesis we will check if there is a left parenthesis in the stack or not. if there is a left parenthesis in the stack then we will pop it from the stack and if there is no left parenthesis in the stack then we will increment the count of right parenthesis. at the end we will return the count of left parenthesis in the stack + count of right parenthesis.
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minInsertions(string s) {
        stack<char> st;
        int count = 0;
        for(int i=0;i<s.size();i++){
            
            if(s[i] == '('){
                st.push('(');
            }

            else{
              
                if(i+1 < s.size() && s[i+1] == ')'){
                    i++;
                }
                else{
                    count++;
                }
     if(!st.empty()){
                st.pop();
            }else{
                count++;
            }
                
            }
       
        }
        return count + 2*st.size();
    }
};