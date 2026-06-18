// now we are doing the BFS and DFS
#include<bits/stdc++.h>
using namespace std;
// class Solution{
//     public:
//     vector<int> bfs(int v,int n, vector<int> adj[]){
//         int vis[n]={0};
//         vis[0]=1;
//         queue<int> q;
//         q.push(0);
//         vector<int> bfs;

//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             bfs.push_back(node);
//             for(auto it:adj[node]){
//                 if(!vis[it]){
//                     vis[it]=1;
//                     q.push(it);
//                 }
//             }
//         }
//         return bfs;
//     }
// };
class Solution{
public:
    void dfs(int node,int n, vector<int> adj[],int vis[],vector<int>& dfs){
        vis[node]=1;
        dfs.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,n,adj,vis,dfs);
            }
        }
    }
 vector<int> dfs(int node,int n, vector<int> adj[],int vis[]){
int vis[n]={0};
int start=0;

vector<int> result;
this->dfs(start,n,adj,vis,result);
return result;

    }
}