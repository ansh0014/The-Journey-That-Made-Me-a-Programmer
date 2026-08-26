// now i am doing the number of sub-arrays of size k and average greater or equal to threshold
// given an array of integers arr and two integers k and threshold , return the number of sub-arrays of size k and average greater than or equal to threshold.
// approach we used sliding window approach
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
int numOfSubarrays(vector<int>&arr, int k , int threshold){
    int n=arr.size();
    int result=0;
    int l,r=0;
    int sum=0;
 for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    if(sum/k>=threshold){
        result++;
    }
    for(int r=k;r<n;r++){
        sum+=arr[r]-arr[l];
        l++;
        if(sum/k>=threshold){
            result++;
        }
    }
    return result;
    
}
};