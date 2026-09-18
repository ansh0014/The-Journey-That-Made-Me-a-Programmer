// now i am doing the jump game 4
// i have given an array of integers arr, i have intially positioned at the first index of the array.
// in one step i can jump from index i to index i+1:
// where i+1 < arr.length.
// i-1 where i-1 >= 0.
// or j where arr[i] == arr[j] and i != j.
// return the minimum number of steps to reach the last index of the array.
// lets think about the approach to solve this problem 
// this is question of bfs+bitmask (or even we don't use bitmask) we can use bfs to solve this problem. we can use a queue to perform the bfs and a set to keep track of the visited indices. each state will be represented by the current index. we will also keep track of the minimum number of steps required to reach the last index. if we reach the last index, we will return the minimum number of steps required. if we exhaust all possible states and cannot reach the last index, we will return -1.
#include <bits/stdc++.h>
using namespace std;
class Solution{
    int bfs(vector<int>& arr, int n){
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        vector<bool> vis(n, false);
        queue<pair<int, int>> q;

        q.push({0,0});
        vis[0] = true;
        while(!q.empty()){
            auto [i, steps] = q.front();
            q.pop();
            if(i == n-1) return steps;
            if(i+1 < n && !vis[i+1]){
                vis[i+1] = true;
                q.push({i+1, steps+1});
            }
            if(i-1 >= 0 && !vis[i-1]){
                vis[i-1] = true;
                q.push({i-1, steps+1});
            }
            for(int j:mp[arr[i]]){
                if(!vis[j]){
                    vis[j] = true;
                    q.push({j, steps+1});
                }
            }
            mp[arr[i]].clear();
        }
        return -1;
    }
    public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        return bfs(arr, n);

    }
};