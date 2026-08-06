// now i am doing the count valid prefixes
// i have given binary string s 
// a prefix of s is consider valid if its characters can be rearranged to form an alternating string.
// Return the number of valid prefixes of s.
// A binary string consisting only of '0' and '1'
// a prefix of string is substring that starts from beginnig of the string and extends to any point within it. 
// a substring is a contiguous sequence of characters within a string.
// an alternating string is a string that does not have two adjacent characters that are equal. for
// exmaple "00101" output is 3 because the valid prefixes are "0","00","001" and "0010" and "00101" are not valid because they have two adjacent characters that are equal.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int countValidPrefixes(string s){
        int n=s.size();
        int count=0;
        int zero=0;
        int one=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') zero++;
            else one++;
            if(abs(zero-one)<=1) count++;
        }
        return count;
    }
};
int main(){
    Solution s;
    string st;
    cin>>st;

    cout<<s.countValidPrefixes(st)<<endl;
    return 0;
}