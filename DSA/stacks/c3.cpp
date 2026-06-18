// now we are doing the next greater element 11
// this question is different from the next greater element 
// how we double the array means not it acutally double the array but we use the modulus for repeat the array
// #include<iostream>
// #include<vector>
// #include<stack>
// using namespace std;
// class Solution{
// public:
// vector<int>nextGreaterElements(vector<int>&nums){
//     int n=nums.size();
//     vector<int>ans(n,-1);
//     stack<int>st;
//     for(int i=0;i<2*n;i++){
//         int num=nums[i%n];
//         while(!st.empty()&&nums[st.top()]<num){
//             ans[st.top()]=num;
//             st.pop();
//         }
//         st.push(i%n);
//     }
//     return ans;
// }
//     };

// NOW i am doing the sum of subarray ranges
// approach in this question we used next greater element and next smaller element then subtract the sum of the subarray minimums from the sum of the subarray maximums and then we will return the answer
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution{
public:
vector<int>findNSE(vector<int>&arr){
    int n=arr.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        int current =arr[i];
        while(!st.empty()&&arr[st.top()]>=arr[i]){
            st.pop();
        }
        ans[i]=st.empty()?-1:st.top();
        st.push(i);


    }
    return ans;
}
vector<int>findNGE(vector<int>&arr){
    int n=arr.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        int current=arr[i];
        while(!st.empty()&&arr[st.top()]<=arr[i]){
            st.pop();
        }
        ans[i]=st.empty()?-1:st.top();
        st.push(i);

    }
    return ans;
}
vector<int>findPGE(vector<int>&arr){
    int n=arr.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        int current =arr[i];
        while(!st.empty()&&arr[st.top()]<=arr[i]){
            st.pop();
        }
        ans[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return ans;
}
vector<int>findPSE(vector<int>&arr){
    int n=arr.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        int current =arr[i];
        while(!st.empty()&&arr[st.top()]<arr[i]){
            st.pop();
        }
        ans[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return ans;
}
long long sumSubarrayMins(vector<int>&arr){
    vector<int>nse=findNSE(arr);
    vector<int>pse=findPSE(arr);
    int n=arr.size();
    long long sum=0;
    for(int i=0;i<n;i++){
        int left=i-pse[i];
        int right=nse[i]-i;
        long long freq=left*right*1LL;
        sum+=(freq*arr[i]*1LL);
    }
    return sum;
}
long long sumSubarrayMaxs(vector<int>&arr){
    vector<int>nge=findNGE(arr);
    vector<int>pge=findPGE(arr);
    int n=arr.size();
    long long sum=0;
    for(int i=0;i<n;i++){
        int left=i-pge[i];
        int right=nge[i]-i;
        long long freq=left*right*1LL;
        sum+=(freq*arr[i]*1LL);
    }
    return sum;
}
long long subArrayRanges(vector<int>&arr){
    long long sumMax=sumSubarrayMaxs(arr);
    long long sumMin=sumSubarrayMins(arr);
    return sumMax-sumMin;
}
};