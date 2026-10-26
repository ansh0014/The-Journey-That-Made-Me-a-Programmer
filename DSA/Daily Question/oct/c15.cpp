// nwo i am doing the longest balanced substring 11 
// i have given a string s consisting only of lthe characters 'a' , 'b' and 'c'
// a substring of s  is called balanced if all distinct characters in the substrings appear the same number of times
// return the length of the longest balanced substring of s.
// approach we used prefix sum and hash map to keep track of the count of each character. we will iterate through the string and for every character we will increment its count in the hash map. we will also keep track of the minimum count of any character in the hash map. if the minimum count is equal to the count of all characters then we have found a balanced substring and we will update the maximum length of balanced substring. at the end we will return the maximum length of balanced substring. 


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   int longestBalanced(string s) {
int n=s.length();
int ans=0;
// first we write the code for one distinct character
int l=0;
for(int i=0;i<n;i++){
    l=(i>0 && s[i]==s[i-1])?l+1:1;
    ans=max(ans,l);
}
// now we implement the two distinct character 
for(char excluded: {'a', 'b', 'c'}){
    int x=0, y=0;
    unordered_map<int,int> mp;
    mp[0]=-1;
    for(int i=0;i<n;i++){
        if(s[i]==excluded){
            x=y=0;
            mp.clear();
            mp[0]=i;
            continue;
        }
        char first = (excluded=='a')?'b':'a';
        if(s[i]==first) x++;
        else y++;
        int diff = x-y;
        if(mp.count(diff)){
            ans=max(ans,i-mp[diff]);
        }else{
            mp[diff]=i;
        }
    }
    int a=0,b=0,c=0;
    unordered_map<string,int>mp2;
    mp2["0,0"]= -1;
    for(int i=0;i<n;i++){
        if(s[i]=='a') a++;
        else if(s[i]=='b') b++;
        else c++;
        int diff1=a-b;
        int diff2=a-c;
        string key=to_string(diff1)+","+to_string(diff2);
        if(mp2.count(key)){
            ans=max(ans,i-mp2[key]);
        }else{
            mp2[key]=i;
        }
    }
}
return ans;


}
};
