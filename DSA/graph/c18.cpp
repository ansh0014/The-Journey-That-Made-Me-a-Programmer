// now i am doing the cheapest flights withing k stops
// i have given the n cities and a list of flights where each flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei
// we have to find the cheapest price from src to dst with at most k stops. If there is no such route, return -1
// for that we are using the priority queue and we have to find the cheapest price from src to dst with at most k stops
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int findCheapestPrice(int n, vector<vector<int>> & fights,int src, int dst,int k){
vector<pair<int,int>>adj[n];
for(int i=0;i<fights.size();i++){
    int u=fights[i][0];
    int v=fights[i][1];
    int wt=fights[i][2];
    adj[u].push_back({v,wt});
}
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
 vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
dist[src][0]=0;
pq.push({0,src,0});
while(!pq.empty()){
    auto [cost,node,stops]=pq.top();
    pq.pop();
    if(node==dst){
        return cost;
    }
    if(stops==k+1){
        continue;
    }
  for(auto it:adj[node]){
    int next=it.first;
    int price=it.second;
    int newcost=cost+price;
    if(newcost<dist[next][stops+1]){
        dist[next][stops+1]=newcost;
        pq.push({newcost,next,stops+1});
  }

}



    }
    return -1;
}
};