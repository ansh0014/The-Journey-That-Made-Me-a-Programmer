// now we are doing the plaindromic substrings
// lets  start with the approach of the of the this question
// i think we have to create the substring and then we have to check the palindromic substring
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     bool isPalindrome(string s){
//         int left=0;
//         int right=s.size()-1;
//         while(left<right){
//             if(s[left]!=s[right]){
//                 return false;
//             }
//             left++;
//             right--;
//         }
//         return true;
//     }
//     int coutnSubstrings(string s){
//         int n=s.size();
//         int count=0;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 string sub=s.substr(i,j-i+1);
//                 if(isPalindrome(sub)){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
// now i am dong the minimum add to make parenthese valid
// this question is done with the stack we make the stack () if this it show empty return 0 if the (( i hav return 2 
// i have to make stack and then i have to check the string if the 
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
int minAddToMakeValid(string s){
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(s[i]);
        }
        else{
            if(!st.empty() && st.top()=='('){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

    }
    return st.size();
}
};