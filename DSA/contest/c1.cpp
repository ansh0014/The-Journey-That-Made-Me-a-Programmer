// i am giving the contest today
// i have given first problem which is traffic signal problem
// if timer==0 then signal is green and timmer ==30 then signal is orange if 30<timer<=90 then red
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
// string trafficSignal(int timer){
//     if(timer==0) return "green";
//     else if(timer==30) return "orange";
//     else if(timer>30 && timer<=90) return "red";
//     else return "Invalid";

// };
// };
// next question is the Count Digit Appearances 
// i have give the interger array nums and the integer digits
// return the total number of times that digits appears in the decimal representation of all elements in nums
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{

//     public:
//     int countDigitOccurrences(vector<int>& nums, int digit) {
//         int count=0;
//         for(int i=0;i<nums.size();i++){
//             string s=to_string(nums[i]);
//             for(int j=0;j<s.size();j++){
//                 if(s[j]-'0'==digit){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }   
// };
// now i am doing the operations to transform array int alternationg prime
// i have arry of nums if the array is consifer alternating prime if elements at even index are prime and elements at odd index are not prime
// input nums=[1,2,3,4] output =3
// explation element at index 0 is prime .increment nums[0]=1 to 2 , using 1 operation
// element at index 1 is not prime .increament nums[1]=2 to 4 , using 2 operation
// the element at index 2 is alredy prime so no operation is needed
// element at index 3 is not prime .
// total operation is 3
// i understand the question let one example [5,6,7,8] output is 0 this is how the element at 0 index and the 2 index is already prime and 1 and 3 index is non prime 
// in question even index is prime and odd index is non prime then we don't have to operate andy operation if this not happend we have to do operarion 
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
// bool isPrime(int n){
//     if(n<=1) return false;
//     for(int i=2;i<=sqrt(n);i++){
//         if(n%i==0) return false;
//     }
//     return true;
// };
// int minOperations(vector<int>& nums){
//     int count=0;
//     for(int i=0;i<nums.size();i++){
//         if(i%2==0){
//             if(!isPrime(nums[i])){
//                 count++;
//             }
//         }
//         else{
//             if(isPrime(nums[i])){
//                 count++;
//             }
//         }
//     }
//     return count;
// }
// };
// now i am doing the maximum value of concatenated number binary segment
// i have given the two integer arrays nums1 and nums0 , each os size n;
// 1) nums1[i] represents the number of '1's in the ith segment
// 2) nums0[i] represents the number of '0' is the ith segment
// for each index i, construct a binary segment consisting of 
// 1) nums1[i] occurences of '1' followed by
// 2) nums0[i] occurences of '0'
// we may rearrange the order of the segments in any way. After rearranging , concatenate all segments to form a signal binary string
// return the maximum possible interger value of the concatenated binary strin g
// since our result can be very large , return it modulo 10^9+7
// example nums1=[1,2] , nums0=[1,0] output ==14
// at index 0, nums1[0]=1 and nums0[0]=1 so the segment formed is "10"
// at index 1, nums1[1]=2 and nums0[1]=0 so the segment formed is "11"
// reordering the segments as "11" followed by the "10" produces the binary string "1110".
// the binary string "1110" has a decimal value of 14
// approach we have to sort the segments in descending order of the number of '1's and then we have to concatenate the segments to form the binary string and then we have to convert the binary string to decimal value and return the result modulo 10^9+7

#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int maxValue(vector<int>& nums1, vector<int>& nums0) {
    int n=nums1.size();
    vector<pair<int,int>> segments;
    for(int i=0;i<n;i++){
        segments.push_back({nums1[i],nums0[i]});
    }
    sort(segments.begin(),segments.end(),[](pair<int,int>& a,pair<int,int>& b){
        return a.first>b.first;
    });
    string binaryString="";
    for(int i=0;i<n;i++){
        binaryString+=string(segments[i].first,'1')+string(segments[i].second,'0');
    }
    long long result=0;
    long long mod=1e9+7;
    for(int i=0;i<binaryString.size();i++){
        result=(result*2+(binaryString[i]-'0'))%mod;
    }
    return result;
}
};
