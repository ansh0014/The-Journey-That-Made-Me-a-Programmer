// now i finding the two non-overlapping sub-array each with targeet sum
// i have given anarray of integers arra and an integer target.
// i have to find two non-overlapping sub array of arr eadch with the sum equal target there can be multiple answers so i ahve to find an answer where the sum of the lenghts of the wwo sub-array is minimyum
// return the minimum sum of the lengths of the two required sub-arrays or retun -1 if there is no such two sub-arrays.
// i  used dp form take which is the minimum length of the sub-array with sum equal to target and then i used sliding window for find the second sub-array with sum equal to target and then i check if the two sub-array are non-overlapping or not if they are non-overlapping then i take the sum of their lengths and update the answer with minimum value of the sum of their lengths.
#include<bits/stdc++.h>

using namespace std;
class Solution {
    public:


     int minSumOfLengths(vector<int>& arr, int target) {
int n=arr.size();
const int INF=1e9;
vector<int> d(n,INF);
int left=0;
int sum=0;
int ans=INF;
for(int r=0; r<n; r++){
    sum+=arr[r];
    while(sum>target){
        sum-=arr[left];
        left++;
    }
    if(sum==target){
        int len=r-left+1;
        if(left>0 && d[left-1]!=INF){
            ans=min(ans,len+d[left-1]);
        }
        if(r==0){
            d[r]=len;
        }
        else{
            d[r]=min(d[r-1],len);
        }
    

    }
else{
  
if(r==0){
            d[r]=INF;
        }
        else{
            d[r]=d[r-1];
        }
}

}

    return ans==INF?-1:ans;
}
};
