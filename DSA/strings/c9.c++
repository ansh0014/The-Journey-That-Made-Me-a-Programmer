// now i am doing the find the index of first occurrence in a string
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     int strStr(string haystack,string needle){
//         int n=haystack.size();
//         int m=needle.size();
//         for(int i=0;i<=n-m;i++){
//             if(haystack.substr(i,m)==needle){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };
// now i am doing the longest Duplicate Substring
// i understand the logic i have to use the k rabin karp algoritm for that and i have to use the hash function for that and then i have to check how many times i have to repeat the string a to make the string b a substring of the repeated string a
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     string longestDupSubstring(string s){
//         int n=s.size();
//         int l=1; 
//         int r=n-1;
//         string ans="";
//         while(l<=r){
//             int mid=l+(r-l)/2;
//             string dup=check(s,mid);
//             if(dup!=""){
//                 ans=dup;
//                 l=mid+1;
//         }else{
//             r=mid-1;
//         }
//     }
//     return ans;
//     }

// private:
// string check(string &s,int len){
//     long long mod=1e9+7;
//     long long p=31;
//     int n=s.size();
//     long long hash=0;
//     long long power=1;
//     // now we compute the p^(len-1)
//     for(int i=0;i<len-1;i++){
//         power=(power*p)%mod;
//     }
//     unordered_map<long long,vector<int>>mp;
//     // now we do first hash
//     for(int i=0;i<len;i++){
//         hash=(hash*p+(s[i]-'a'+1))%mod;
//     }
//     mp[hash].push_back(0);
//     // now we apply the sliding window
//     for(int i=len;i<n;i++){
//         hash=(hash-(s[i-len]-'a'+1)*power%mod+mod)%mod;
//         // now we add the new character
//         hash=(hash*p+(s[i]-'a'+1))%mod;
//         int start=i-len+1;
//         if(mp.count(hash)){
//             for(auto index:mp[hash]){
//                 if(s.substr(index,len)==s.substr(start,len)){
//                     return s.substr(start,len);
//                 }
//             }
//         }
//         mp[hash].push_back(start);
//     }
//     return "";
// }


// };
