// Given a string s, return the minimum number of operations needed to make s sorted in non-decreasing order.
// this question is of greedy approach we have to count the number of operations needed to make the string sorted in non-decreasing order we have to count the number of characters that are less than the maximum character we have seen so far if we find a character that is less than the maximum character we have seen so far then we have to increment the count of operations needed to make the string sorted in non-decreasing order
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int minOperations(string s){
    int n=s.size();
    int count=0;
    char maxChar=s[0];
    // means input is "gf" i have to return -1
    if(n<2) return -1;
    for(int i=1;i<n;i++){
    // edge case if charcter is less than two
    

        if(s[i]<maxChar){
          count++;
        }
        else{ 
        maxChar=s[i];

    }
    }
    return count;
}
};