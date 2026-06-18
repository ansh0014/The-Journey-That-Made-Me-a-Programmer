// now i am doing the Find the K-sum of an array
// i ahve to make subsequeces of the summ of array and then with the give value of k i ahve to give the no. becuse k=index of the sorted array of subsequences sum
// approach first i have to find the sum of all subsequeces for that first i have to create the subbarry for that i am using sliding window approach and then i have to sort the array of subsequeces sum and then i have to return the k-1 th element of the sorted array of subsequeces sum
#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
  long long kSum(vector<int>& nums,int k){
    int n=nums.size();
    vector<long long>subseqSum;
    for(int i=0;i<(1<<n);i++){
        long long sum=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                sum+=nums[j];
            }
        }
        subseqSum.push_back(sum);
    }
     sort(subseqSum.begin(),subseqSum.end(),greater<long long>());
    return subseqSum[k-1];

  }
};