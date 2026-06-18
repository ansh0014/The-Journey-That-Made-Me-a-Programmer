// Today i am doing the contest on leetcode
// first question is find the degree of each vertex
// this question is simple 2d matrix i have to find using simple two loop
#include<bits/stdc++.h>
using namespace std;
class Solution{
vector<int> findDegrees(vector<vector<int>>& matrix){
    int n=matrix.size();
    vector<int> degree(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1){
                degree[i]++;
            }
        }
    }
    return degree;
}
};
// next question si angles of a triangle
// answer is with 1e-5 precision 
// this is queston of i have to use side to check the angle of triangle and then i have to use the formula to find the angle of triangle
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     vector<double> internalAngles(vector<int>& sides){
//         double a=sides[0];
//         double b=sides[1];
//         double c=sides[2];
//         double A=acos((b*b+c*c-a*a)/(2*b*c));
//         double B=acos((a*a+c*c-b*b)/(2*a*c));
//         double C=acos((a*a+b*b-c*c)/(2*a*b));
//         return {A,B,C};
//     }

// };
// NOW i am doing the longest balanced substring after one
// i have give a binary string s consisting only characters '0' and '1'. A string is balance if it contains an equal numbers of '0' and '1' . edgec case i have perform at most one swap between tow characters in s 
// examples s="100001" output is 4 swap 101000 
// approach first i have to count the number of 0 and 1 in the string then i have to find the longest balanced substring by using sliding window approach if i found the balanced substring then i will check if it is greater than the previous longest balanced substring then i will update the longest balanced substring and then i will return the longest balanced substring
// this question is binary search question i have to find the longest balanced substring by using binary search approach if i found the balanced substring then i will check if it is greater than the previous longest balanced substring then i will update the longest balanced substring and then i will return the longest balanced substring
// this question is hashmap + binary + prefix
// input is "10001" output is 4 swap 101000

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int longestBalanced(string s){
        int n=s.size();
        // this question of binary+hashmap+prefix sum i have to count the number of 0 and 1 in the string and then i have to find the longest balanced substring by using prefix sum and hashmap if i found the balanced substring then i will check if it is greater than the previous longest balanced substring then i will update the longest balanced substring and then i will return the longest balanced substring
unordered_map<int,int>mp;
int count0=0,count1=0;
int longest=0;
int sum=0;
mp[0]=-1;
for(int i=0;i<n;i++){
    if(s[i]=='1'){
        sum+=1;
        count1++;
    }else {
        sum-=1;
        count0++;
    }
    if(mp.find(sum)!=mp.end()){
        longest=max(longest,i-mp[sum]);
    }else{
        mp[sum]=i;
    }
}    
int maxBalanced=min(count0,count1)*2;
return min(longest+2,maxBalanced);

}

};