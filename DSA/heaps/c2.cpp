// now i am doing the Top K frequent element
// i will use the hash map to store the frequency of each element and then i will use the priority queue to store the top k frequent element
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//   vector<int> topKFrequent(vector<int>& nums,int k){
//     unordered_map<int,int>m;
//     for(int i=0;i<nums.size();i++){
//         m[nums[i]]++;
//     }
//     priority_queue<pair<int,int>>pq;
//     for(auto it:m){
//         pq.push({it.second,it.first});
//     }
//     vector<int> ans;
//     for(int i=0;i<k;i++){
//         ans.push_back(pq.top().second);
//         pq.pop();
//     }
//     return ans;
//   }  
// };
// now i am doing the kth largest element in a stream
// i have use the priority queue to store the k largest element in the stream and then i will return the top element of the priority queue as the kth largest element in the stream
// i have to use the min heap to store the k largest element in the stream because the top element of the min heap will be the kth largest element in the stream
#include<bits/stdc++.h>
using namespace std;
class KthLargest{
    public:
    int k;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>&nums){
        this->k=k;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    int add(int val){
        pq.push(val);
        if(pq.size()>k){
            pq.pop();
        }
        return pq.top();
    }
};