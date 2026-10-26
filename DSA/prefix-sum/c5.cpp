// now i am doing the prefix scores of strings 
// i have given a array words of size n consisting of non-empty strings
// we define the score of a string term as the number of strings words[i] such that term is a prefix of words[i]
// For example, if words = ["a", "ab", "abc", "cab"], then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
// Return an array answer of size n where answer[i] is the sum of scores of every non-empty prefix of words[i]
// so i am thinking we have breakdown the simple string in prefix 
// words=["abc","ab","bc","b"]
// so we have break "abc" is a,ab, abc so int that ab is 2 a is 2 and abc is 1 so total is 5
// ab we divide a and ab so it is a is 2 and ab is 2 so total is 4
// bc we divide b and bc so it is b is 2 and bc is 1 so total is 3
// b we divide b so it is 2 so total is 2
// we make tree prefix tree to solve this 
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    
     vector<int> sumPrefixScores(vector<string>& words) {
    


         
    }
};