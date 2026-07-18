// Minimum Threshold path with limited heavy edges
// i have given an undirected weighted graph with n nodes labeled from 0 to n -1
// the graph is represented by a 2D integer array edges, where each edge edges[i]=[ui,vi,wi] indicates that there is an undirected edge between nodes ui and vi with weight wi
// i have integers source, target, and k
// A threshold value determines whether an edge is considered light or heavy.
// An edge is light if its weight is less than or equal to threshold.
// an edge is heavy if its weight is greater than threshold.
// a path from source to target is valid if it contains at most k heavy edges.
// return the minimum threshold
// let's write the approach first we write the code to make the graph then we write the priority queue to find the minimum threshold path with limited heavy edges
// ok i have write to make also code of light and heavy i have to write the condition to check if the edge is light or heavy and then we have to check if the path is valid or not if it is valid then we have to return the minimum threshold
// i have apply dijkstra's algorithm to find the minimum threshold path with limited heavy edges
// the apply binary search to find the minimum threshold
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
bool isValid(int n, vector<vector<pair<int,int>>>& graph, int source, int target, int k, int threshold){
vector<int>heavy(n,INT_MAX);
 priority_queue<pair<int,int>,  vector<pair<int,int>>, greater<pair<int,int>>> pq;
heavy[source]=0;
pq.push({0, source});
while(!pq.empty()){
    auto [it,u]=pq.top();
    pq.pop();
    if(it>heavy[u]) continue;
    if(u==target) return it<=k;
    for(auto &[v,w]: graph[u]){
        int newHeavy=it+(w>threshold);
        if(newHeavy<heavy[v]){
            heavy[v]=newHeavy;
            pq.push({newHeavy, v});
        }
    }

}
    return false;
}
int minimumWeight(int n, vector<vector<int>>& edges, int source, int target, int k) {
if(source==target) return 0;
vector<vector<pair<int,int>>> graph(n);
for(auto &edge: edges){
    graph[edge[0]].push_back({edge[1], edge[2]});
    graph[edge[1]].push_back({edge[0], edge[2]});
}
int left=0, right=1e9, ans=-1;
while(left<=right){
    int mid=left+(right-left)/2;
    if(isValid(n, graph, source, target, k, mid)){
        ans=mid;
        right=mid-1;
    }else{
        left=mid+1;
    }
}
return ans;




}
};