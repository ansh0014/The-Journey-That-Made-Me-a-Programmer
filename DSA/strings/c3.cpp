// now i am doing the roman to integer
// thsi is question is hashing and string % because last digit like sutff i have to add digitn once tens humdererd then add like
// i have to add 10 and 100 and 1000 like that
// #include<iostream>
// #include<string>
// #include<unordered_map>
// using namespace std;
// class Solution{
//     public:
//     int romanTOInt(string s){
//         unordered_map<char,int>mp;
//         mp['I']=1;
//         mp['V']=5;
//         mp['X']=10;
//         mp['L']=50;
//         mp['C']=100;
//         mp['D']=500;
//         mp['M']=1000;
//         int n=s.size();
//         int sum=0;
//         for(int i=0;i<n;i++){
//             if(i<n-1&&mp[s[i]]<mp[s[i+1]]){
//                 sum+=mp[s[i+1]]-mp[s[i]];
//                 i++;
//             }else{
//                 sum+=mp[s[i]];
//             }
//         }
//         return sum;
//     }

// };
// now we are doing the maximum nesting depth of parentheses
// in this question we have to find the nested parentheses 
// we have to make the stack compare the opening and closing parentheses and we have to find the maximum depth of the parentheses
// #include <bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
// int maxDepth(string s){
//     stack<char>st;
//     int maxdepth=0;
//     for(char c:s){
//         if(c=='('){
//             st.push(c);
//             maxdepth=max(maxdepth,(int)st.size());
//         }
//         if(c==')'){
//             if(!st.empty()){
//                 st.pop();
//             }            

//         }
//     }
//     return maxdepth;
// }
// };
// now we are doing the count and say
// i am not undestanding the question how i replace the no.
// example  n=4 the count say is 1,11,21,1211
// i have to understand the question how to replace the no.
// i understand the quection 1=1 2=1+1 3=2+1 4=1+2+1
// so i think in this question we have to count the number of digits and then say the number of digits like 1 is one 1 so 11 is two 1 so 21 is one 2 and one 1 so 1211 is one 1 two 2 and one 1
// approach this question is done we brake the no. the in digits which is the count and then we have to say the number of digits like 1 is one 1 so 11 is two 1 so 21 is one 2 and one 1 so 1211 is one 1 two 2 and one 1

// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     string countAndSay(int n){
//         if(n==1) return "1";
//         string prev=countAndSay(n-1);
//         string result="";
//         int count=1;
//         for(int i=1;i<prev.size();i++){
//             if(prev[i]==prev[i-1]){
//                 count++;
//             }else{
//                 result+=to_string(count)+prev[i-1];
//                 count=1;
//             }
//         }
//         result+=to_string(count)+prev.back();
//         return result;
//     }
// };