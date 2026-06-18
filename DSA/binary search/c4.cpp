// now i am doing the minimum number of days to days to amke m bouquets
// m is the minimum number of bouquet and k is the number of adjacent flowers in one bouquet and then i have to find the minimum number of days to make m bouquets
// approach first i have to find the maximum number of days to bloom all the flowers and then i have to apply binary search on the number of days and then i will check if it is possible to make m bouquets in mid number of days if it is possible then i will move the high pointer to mid else i will move the low pointer to mid+1
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{

//     public:
//     bool isPossible(vector<int>& bloomDay,int m,int k,int mid){
//         int count=0;
//         int bouquet=0;
//         for(int i=0;i<bloomDay.size();i++){
//             if(bloomDay[i]<=mid){
//                 count++;
//                 if(count==k){
//                     bouquet++;
//                     count=0;
//                 }
//             }
//             else{
//                 count=0;
//             }
//         }
//         return bouquet>=m;
//     }
// int minDays(vector<int>& bloomDay,int m,int k){
//     int n=bloomDay.size();
// int l=*min_element(bloomDay.begin(),bloomDay.end());
// int h=*max_element(bloomDay.begin(),bloomDay.end());
// int ans=-1;
// while(l<=h){
//     int mid=l+(h-l)/2;
//     if(isPossible(bloomDay,m,k,mid)){
//         ans=mid;
//         h=mid-1;
//     }
//     else{
//         l=mid+1;
//     }
 



// }
//    return ans;
// }
// };
// now i am doing the smallest divisor given a threshold
// i understand i have to find the smalles divisor which i divide the whole array then i have to mae the summ the threshold i have to return the smallest divisor
// approach first i have to find the maximum element in the array and then i have to apply binary search on the divisor from 1 to maximum element and then i will check if it is possible to divide the array with mid divisor and get the sum less than or equal to threshold if it is possible then i will move the high pointer to mid else i will move the low pointer to mid+1
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
// int smallestDivisor(vector<int>& nums,int threshold){
//     int n=nums.size();
//     // int l=*min_element(nums.begin(),nums.end());
//     int l=1;
//     int h=*max_element(nums.begin(),nums.end());
//     int ans=-1;
//     while(l<=h){
//         int mid=l+(h-l)/2;
//         long long sum=0;
//         for(int i=0;i<n;i++){
//             sum+=(nums[i]+mid-1)/mid;
//         }
//         if(sum<=threshold){
//             ans=mid;
//             h=mid-1;
//         }
//         else{
//             l=mid+1;
//         }
//     }
//     return ans;
// }

// };

// now i am doing the capacity to ship packages within D days
// i understand i have to find the minimum capacity of ship to ship all the packages within D days
// approach first i have to find the maximum weight of the package and then i have to apply binary search on the capacity from maximum weight to sum of all weights and then i will check if it is possible to ship all the packages within D days with mid capacity if it is possible then i will move the high pointer to mid else i will move the low pointer to mid+1
// i understand the question have to divide the weights into D days sum+=weights[i]<=mid if sum>mid then i will move to next day and count++ if count>D then it is not possible to ship all the packages within D days with mid capacity
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
int shipWithinDays(vector<int>& weights,int days){
    int n=weights.size();
    
  int l = *max_element(weights.begin(), weights.end()); 
   int h = accumulate(weights.begin(), weights.end(), 0);
    int ans=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        int sum=0;
        int count=1;
        for (int i = 0; i <n; i++)
        {
        sum+=weights[i];
        if(sum>mid){
            count++;
            sum=weights[i];

        }
    
        }
     if(count<=days){
        ans=mid;
        h=mid-1;
     }
     else{
        l=mid+1;
     }   
    }
return ans;
      

}
};