// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void f(int ind, int sum, vector<int> &arr, vector<int> &ans) {

//     if (ind == arr.size()) {
//         ans.push_back(sum);
//         return;
//     }

//     f(ind + 1, sum + arr[ind], arr, ans);

//     f(ind + 1, sum, arr, ans);
// }

// int main() {
//     vector<int> arr = {1, 2, 2}; 
//     vector<int> ans;

//     f(0, 0, arr, ans);


//     sort(ans.begin(), ans.end());

//     for (int x : ans) {
//         cout << x << " ";
//     }

//     return 0;
// }
// now i am doing the letter combinations of a phone numbers
// approach i have to create a map of digits and then i have to do the backtracking for the possible letter combinations and then return the answer
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void Solve(string &digits, int index,string &current, vector<string> &ans, unordered_map<char,string> &mp){
        if(index==digits.size()){
            ans.push_back(current);
            return;
        }
        char digit=digits[index];
        string letters=mp[digit];
        for(char letter:letters){
            current.push_back(letter);
            Solve(digits,index+1,current,ans,mp);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits){
if(digits.empty()) return {};
unordered_map<char,string>mp;
mp['2']="abc";
mp['3']="def";  
mp['4']="ghi";
mp['5']="jkl";
mp['6']="mno";
mp['7']="pqrs";
mp['8']="tuv";
mp['9']="wxyz";
vector<string>ans;
string current="";
    Solve(digits, 0, current, ans, mp);
    return ans;
}
};
