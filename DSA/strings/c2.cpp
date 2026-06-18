// now we are doing the isomorphic strings
// ok in this question i have to check the valid strings means i have to traverse the string and check the mapping of the characters
// #include<iostream>
// #include<string>
// #include<vector>
// #include<unordered_map>
// using namespace std;
// class Solution{
// public:
// bool isIsomorphic(string s, string t){
// int n=s.size();
// unordered_map<char,char>mp;
// if(n!=t.size()){
//     return false;
// }
// for(int i=0;i<n;i++){
//     char ch1=s[i];
//     char ch2=t[i];
//     if(mp.count(ch1)){
//         if(mp[ch1]!=ch2){
//             return false;
//         }
//     }else{
//         mp[ch1]=ch2;
//     }

// }
// unordered_map<char,char>mp2;
// for(int i=0;i<n;i++){
//     char ch1=s[i];
//     char ch2=t[i];
//     if(mp2.count(ch2)){
//         if(mp2[ch2]!=ch1){
//             return false;
//         }
//     }else{
//         mp2[ch2]=ch1;
//     }

// }
// return true;
// }
// };
// now we are doing the sum of beauty of all substrings
// approach this quuestion is of hashing and sliding window combination because i have to generate the substring and then we give hte beauty of 1 to one substring
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include <climits>

using namespace std;
class Solution
{
public:
    int beautySum(string s)
    {
        int n = s.size();
        int sum = 0;
        // this loop is for generating the substring and then we give the beauty of 1 to one substing and then we will check the max frequency and min frequency of the characters in the substring and then we will add the beauty of the substring to the sum
        for (int i = 0; i < n; i++)
        {
            // we create the hashmap for counting the frequency
            unordered_map<char, int> mp;
            // this second loop is for generating the substring and then we give the beauty of 1 to one substing and then we will check the max frequency and min frequency of the characters in the substring and then we will add the beauty of the substring to the sum
            for (int j = i; j < n; j++)
            {
                mp[s[j]]++;
                int maxFreq = 0;
                int minFreq = INT_MAX;
                // this loop is for checking the max frequency and min frequency of the characters in the substring and then we will add the beauty of the substring to the sum
                // instead of auto we can also use the pair<char,int> for checking the max frequency and min frequency of the characters in the substring and then we will add the beauty of the substring to the sum
                // we used different loop
                // for (int k = 0; k < 26; k++)
                // {
                //     char ch = 'a' + k;
                //     if (mp.count(ch))
                //     {
                //         maxFreq = max(maxFreq, mp[ch]);
                //         minFreq = min(minFreq, mp[ch]);
                //     }
                // }
                // this loop is more optimized because we used auto which means we have to traverse only the characters which are present in the substring and then we will check the max frequency and min frequency of the characters in the substring and then we will add the beauty of the substring to the sum
                for (auto &p : mp)
                {
                    maxFreq = max(maxFreq, p.second);
                    minFreq = min(minFreq, p.second);
                }
                sum += maxFreq - minFreq;
            }
        }
        return sum;
    }
};
