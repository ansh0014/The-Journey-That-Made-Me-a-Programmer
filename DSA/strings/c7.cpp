// now i am doing the bulls and cows 
// this question seems like the string mask
// i want to understand the input and the output 
// input is a string secret and a string guess and output is a string in the format of "xAyB" where x is the number of bulls and y is the number of cows
// now it secret ="1807" , guess ="7810"
// output is "1A3B" because there is one bull which is 8 and there are three cows which are 1,0 and 7
// approach first i have to count the number of bulls and then i have to count the number
// then how i get the 1A3B from the input
// approach first i have to count the number of bulls and then i have to count the number of cows and then i have to return the string in the format of "xAyB" where x is the number of bulls and y is the number of cows
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
// string getHint(string secret,string guess){
//     int bulls=0;
//     int cows=0;
//     unordered_map<char,int>mp;
//     int n=secret.size();
//     for(int i=0;i<n;i++){
//         if(secret[i]==guess[i]){
//             bulls++;
//         }else{
//             mp[secret[i]]++;
//         }

//     }
//     for(int i=0;i<n;i++){
//         if(secret[i]!=guess[i]&&mp[guess[i]]>0){
//             cows++;
//             mp[guess[i]]--;
//         }
//     }
//     return to_string(bulls)+"A"+to_string(cows)+"B";
// }
// };
// now i am doing the repeated string match
// i understand the logic i have to make the substring of a which is substring of b and then i have to check how many times i have to repeat the string a to make the string b a substring of the repeated string a
// i have to use the Rabin-Karp algorithm for that and i have to use the hash function for that and then i have to check how many times i have to repeat the string a to make the string b a substring of the repeated string a
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     int repeatedStringMatch(string a, string b){
//         int temp=0;
//         int count=0;
//         while(temp<b.size()){
//             temp+=a.size();
//             count++;
//         }
//         string s="";
//         for(int i=0;i<count;i++){
//             s+=a;
//         }
//         if(s.find(b)!=string::npos) return count;
//         s+=a;
//         if(s.find(b)!=string::npos) return count+1;
//         return -1;
        

//     }
// };