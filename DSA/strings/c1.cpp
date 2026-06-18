// #include<iostream>
// using namespace std;
// int main(){
//     char name[20];
//     cout<<"Enter your name:";
//     cin>>name;
//     cout<<"Your name is"<<name;
//     return 0;
// }
// now we do leetcode style make template 
// #include<iostream>
// #include<string>
// #include<algorithm>
// using namespace std;
// class Solution{
//     public:
// void reverstring(string s){
// int n=s.size();
// int st=0;
// int end=n-1;
// while(st<end){
//     swap(s[st],s[end]);
//     st++;
//     end--;
// }

//     }
// };
// now we do the reverse words in a string ll
// #include<iostream>
// #include<string>
// #include<algorithm>
// using namespace std;
// class Solution{
//     string reverseStr(string s, int k){
//         // approach i am thinking about the sliding window 
//         int n=s.size();
//         for(int i=0;i<n;i+=2*k){
//             int st=i;
//             int end=min(i+k-1,n-1);
//             while(st<end){
//                 swap(s[st],s[end]);
//                 st++;
//                 end--;
//             }
//         }
//         return s;

//     }
// };
// now i am doing the largest odd number in string
// #include<iostream>
// #include<string>
// using namespace std;
// class Solution{
// public:
// string largestOddNumber(string num){
//     int n=num.size();
//     for(int i=n-1;i>=0;i--){
//         // /this loop is for traversing the string from the end and checking for the first odd number and then we will return the substring from 0 to that index
//         if((num[i]-'0')%2!=0){
//             return num.substr(0,i+1);
//         }
//     }
//     return "";
// }
// };
// now we do the longest common prefix
// apprach in this question we used the sliding window approach 
// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;
// class Solution{
// public:
// string longetCommonPrefix(vector<string>&strs){
//     int n=strs.size();
//     if(n==0){
//         return "";
//     }
//     int l=0;
//     int r=strs[0].size()-1;
//     while(l<=r){
//         char ch=strs[0][l];
//         for(int i=1;i<n;i++){
//             if(strs[i].size()<=l || strs[i][l]!=ch){
//                 return strs[0].substr(0,l);
//             }
//         }
//         l++;
//     }
//     return strs[0];
    
// }
// };

// now we do the rotate string
// in this question we will check reverse the string and then check if it rotate then we give true otherwise false
// #include<iostream>
// #include<string>
// using namespace std;
// class Solution{
// public:
// bool rotatestring(string s, string goal){
//     int n=s.size();
//     for(int i=0;i<n;i++){
//         if(s==goal){
//             return true;
//         }else{
//             char ch=s[0];
//             s.erase(s.begin());
//             s.push_back(ch);

//         }
//     }
//     return false;
// }
// };
// now i am dong sort characters by frequency
// this question of hashing and sorting 
// i have to make the hasmap unordered_map then sorting
// #include<iostream>
// #include<string>
// #include<vector>
// #include<unordered_map>
// #include<algorithm>
// using namespace std;
// class Solution{
//     public:
// string frequencySort(string s){
    
//     int n=s.size();
    
//     unordered_map<char ,int>mp;
//     for(char c: s){
//         mp[c]++;
//     }
//     vector<pair<char,int>>v(mp.begin(),mp.end());
//     sort(v.begin(),v.end(),[](pair<char,int>&a,pair<char,int>&b){
//         return a.second>b.second;
//     });
  
//     string result="";
//     for(auto& p: v){
//         result+=string(p.second,p.first);
//     }
//     return result;

// }
// };
// now we are doing he longest palindromi substring
// we i see word longest plindormic sustring i think about the sliding window 
// approcah this question we used the sliding window and check the palindromic substring
// i have to makes notes on that question

#include<iostream>
#include<string>
using namespace std;
class Solution{
    public:
string longstPalindrome(string s){
    int n=s.size();
    if(n==0) return "";
    int l=0;
    int maxLength=1;
    // this loop is for traversing the string and checking for the palindromic substring

    for (int i = 0; i < n; i++)
    {
    int st=i;
    int end=i;
    // we used while loop for checking the palindromic substring and if we find the palindromic substring then we will check the length of the substring and if it is greater than the maxLength then we will update the maxLength and the starting index of the substring

    while(st>=0&&end<n&&s[st]==s[end]){
        // if condition is for checking the palindromic substring and if we find the palindromic substring then we will check the length of the substring and if it is greater than the maxLength then we will update the maxLength and the starting index of the substring

        if(end-st+1>maxLength){
            l=st;
            maxLength=end-st+1;
        }
        // this is for updating the starting index and the maxLength of the substring
        st--;
        end++;  

    }
    st=i;
    end=i+1;
    // this loop is for checking the even length palindromic substring and if we find the even length palindromic substring then we will check the length of the substring and if it is greater than the maxLength then we will update the maxLength and the starting index of the substring
    while(st>=0&&end<n&&s[st]==s[end]){
        if(end-st+1>maxLength){
            l=st;
            maxLength=end-st+1;
        }
        st--;
        end++;  

    }
    }
    // function substr() is used to return the substring of the string and it takes two parameters the starting index and the length of the substring and it returns the substring of the string from the starting index to the length of the substring
    
    return s.substr(l,maxLength);

    
}
};