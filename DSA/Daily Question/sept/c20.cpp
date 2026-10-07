// now i am doing the evaluate the bracket paris of a string
// You are given a string s that contains some bracket pairs, with each pair containing a non-empty key.

// For example, in the string "(name)is(age)yearsold", there are two bracket pairs that contain the keys "name" and "age".
// You know the values of a wide range of keys. This is represented by a 2D string array knowledge where each knowledge[i] = [keyi, valuei] indicates that key keyi has a value of valuei.

// You are tasked to evaluate all of the bracket pairs. When you evaluate a bracket pair that contains some key keyi, you will:

// Replace keyi and the bracket pair with the key's corresponding valuei.
// If you do not know the value of the key, you will replace keyi and the bracket pair with a question mark "?" (without the quotation marks).
// Each key will appear at most once in your knowledge. There will not be any nested brackets in s.

// Return the resulting string after evaluating all of the bracket pairs.
// we use the map to store the key value pair and then we can iterate through the string and when we encounter a opening bracket we can find the closing bracket and get the key and check if it is present in the map or not if present we can replace it with the value else we can replace it with ? and finally return the string
// for brackets we can use the find function to find the closing bracket and get the key in between the brackets
// we used the replace function to replace the key with the value or ? in the string
// we have to think about the hashmap to store the key value pair and then we can iterate through the string and when we encounter a opening bracket we can find the closing bracket and get the key and check if it is present in the map or not if present we can replace it with the value else we can replace it with ? and finally return the string
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string solve(string s, vector<vector<string>>& knowledge){
        unordered_map<string, string> mp;
        for (auto &k : knowledge) {
            mp[k[0]] = k[1];
        }
        string r;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                int j=s.find(')',i);
                string key=s.substr(i+1,j-i-1);
                if(mp.find(key)!=mp.end()){
                    r+=mp[key];
                }else{
                    r+='?';
                }
                i=j;
            }else{
                r+=s[i];
            }
        }
        return r;
    }
    string evaluate(string s, vector<vector<string>>& knowledge) {
        

    }
};