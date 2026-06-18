// now i am doing the detect a cycle using the bfs khan's algorithm
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     bool isCyclic( int V , vector<int> adj[]){
//         vector<int>indegree(V,0);
//         for(int i=0;i<V;i++){
//             for(auto it:adj[i]){
//                 indegree[it]++;
//             }
//         }
//         queue<int>q;
//         for(int i=0;i<V;i++){
//             if(indegree[i]==0){
//                 q.push(i);
//             }
//         }
//         vector<int>topo;
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             topo.push_back(node);
//             for(auto it:adj[node]){
//                 indegree[it]--;
//                 if(indegree[it]==0){
//                     q.push(it);
//                 }
//             }
//         }
//         if(topo.size()==V){
//             return false;
//         }
//         return true;
//     }
// };
// now i am doing the course schdule
// this question of topological sort
// i can use dfs for that 
// dfs means stack and make the visited array and make the recursion stack and if i find the node which is already in the recursion stack then there is a cycle in the graph and i cannot complete all the courses
#include<bits/stdc++.h>
using namespace std;
class Solution{
        bool dfs(int node,vector<int>adj[],vector<int>&visited,vector<int>&recStack){
            visited[node]=1;
            recStack[node]=1;
            for(auto it:adj[node]){
                if(!visited[it]){
                    if(dfs(it,adj,visited,recStack)){
                        return true;
                    }
                }
                else if(recStack[it]){
                    return true;
                }
            }
            recStack[node]=0;
            return false;
        }
    public:
    bool canFinish(int numCourses,vector<vector<int>>&prerequistes){
        int V=numCourses;
        vector<int>adj[V];
        int n=prerequistes.size();
        for(int i=0;i<n;i++){
            adj[prerequistes[i][1]].push_back(prerequistes[i][0]);
        }
        vector<int>visited(V,0);
        vector<int>recStack(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,recStack)){
                    return false;
                }
            }
        }
        return true;

    }
};