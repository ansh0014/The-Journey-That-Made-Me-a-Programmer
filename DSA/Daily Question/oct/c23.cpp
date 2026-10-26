// now i am doing the maximize sum of squares of digits
// i have given two poistive integers num and sum.
// a poistive integer n is good if it satifies both of the following
// teh number of digits in n is exactly num.
// the sum of digits in n is exactly sum.
// the score of a good integer n is teh sum of the squares of digits in n.
// return the string denoting the good integer n that achieves the maximum score. IF there are multiple possible integers reuturn the maximum one. If no such integer exists return the empty string
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
      string maxSumOfSquares(int num, int sum) {
     
        string ans="";
    // first condtion the number of digits in is exactly num
    // the sum of digits in n is exactly sum
    if(sum>num*9) return "";
    for(int i=0;i<num;i++){
        int digit=min(9,sum);
        ans+=to_string(digit);
        sum-=digit;
    }
    return ans;
}
};