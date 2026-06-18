// now i am doing the shortest palindrome

// i undestand the question i have to charcter to make the palindrom 
// lets take example input is aacecaaa
// output is aaacecaaa we add a at the staring it plaindrome a-->a a---> a---> means first therre a is plindrom to last thrre a c--->c
// i think we use the sliding window approach we have to start from the end of the string and then we have to check the palindrom if it is not palindrom then we have to move the end pointer to left and then we have to check the palindrom again if it is palindrom then we have to add the remaining string at the starting of the string and return the answer

// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
// string shortestPalindrome(string s) {
// int n=s.size();
// int l=0,r=n-1;
// unordered_map<char,int>mp;
// while(r>=0){
//     if(s[l]==s[r]){
//         l++;
//     }
// r--;
    
// }
// if(l==n){
//     return s;
// }

// string add=s.substr(l);
// string rev=add;
// reverse(rev.begin(),rev.end());
// return rev+shortestPalindrome(s.substr(0,l))+add;

// }
// };
