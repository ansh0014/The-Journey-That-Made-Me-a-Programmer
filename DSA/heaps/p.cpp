// now i am doing the kth element in a array
// condition i don't have to use sorting and i have to do it in o(n) time complexity
// i have to use the heap data structure to solve this problem
// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<queue>
// #include<iomanip>
// using namespace std;
// class Solution{
//     public:
//     int findKthLargest(vector<int>& nums, int k){
//        priority_queue<int> maxHeap;
//         for(int i = 0; i < nums.size(); i++) {
//             maxHeap.push(nums[i]);
//         }
//         for(int i = 1; i < k; i++) {
//             maxHeap.pop();
//         }
//         return maxHeap.top();
//     }

// };
// i am using the priority queue to make the max heap and min heap
#include<bits/stdc++.h>
using namespace std;
class maxHeap{
    public:
    priority_queue<int> pq;
    void insert(int val){
        pq.push(val);
    }
    int getMax(){
        return pq.top();
    }
    void deleteMax(){
        pq.pop();
     }
};
class minHeap{
    public:
    priority_queue<int, vector<int>, greater<int>> pq;
    void insert(int val){
        pq.push(val);
    }
    int getMin(){
        return pq.top();
    }
    void deleteMin(){
        pq.pop();
     }
};
