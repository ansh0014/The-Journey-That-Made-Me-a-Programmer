// now i am doing the zigzag conversion
// i have given the string "PAYPALISHING" is written in a zigzap pattern on a given number of rows like this:(you may want to display this pattern in fixed font for better legibility)
// approach we used the two pointer approach to solve this problem. we can use two pointers to traverse the string and add the characters to the corresponding rows. we can use a vector of strings to store the characters of each row. we can use a variable to keep track of the current row and a variable to keep track of the direction of traversal. we can use a for loop to traverse the string and add the characters to the corresponding rows. we can use a while loop to traverse the rows and add the characters to the final string.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
string convert(string s, int numRows){
    int l,r=0;
    vector<string>v(numRows);
    while(r<s.size()){
        for(l=0;l<numRows && r<s.size();l++){
            v[l]+=s[r++];
        }
        for(l=numRows-2;l>0 && r<s.size();l--){
            v[l]+=s[r++];
        }
    }
    return accumulate(v.begin(),v.end(),string());
}
};