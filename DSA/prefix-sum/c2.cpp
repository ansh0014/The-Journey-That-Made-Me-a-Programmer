// now i am doing he count of Range Sum
// i have given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower,upper] inclusive.
// Range sun S(i,j) is defined as the sum of the elements in nums between indices i and j inclusive, where i<=j
// i have to use the prefix sum and then i will use the merge sort to count the number of range sums that lie in [lower,upper] inclusive.
// we used the hashmap for countring -ve value because it works easliy
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int mergeSort(vector<long long>&prefix,int l,int r,int lower,int upper){
    if(l>=r) return 0;
    int m=(l+r)/2;
    int j=m+1,k=m+1;
    int ans=0;
    ans+=mergeSort(prefix,l,m,lower,upper);
    ans+=mergeSort(prefix,m+1,r,lower,upper);
    for(int i=l;i<=m;i++){
        while(j<=r && prefix[j]-prefix[i]<lower) j++;
        while(k<=r && prefix[k]-prefix[i]<=upper) k++;
        ans+=k-j;
    }
    
    sort(prefix.begin()+l,prefix.begin()+r+1);
    return ans;
}
int countRangeSum(vector<int>&nums,int lower,int upper){
    int n=nums.size();
    vector<long long>prefix(n+1,0);
    for(int i=0;i<n;i++){
        prefix[i+1]=prefix[i]+nums[i];
    }
    return mergeSort(prefix,0,n,lower,upper);

}
};
