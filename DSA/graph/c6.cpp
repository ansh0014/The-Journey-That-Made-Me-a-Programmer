// now i am doing the number of provices
// i have to used the dfs for that 
#include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     void dfs(int node,vector<vector<int>>& isConnected,vector<bool>& visited){
//         visited[node]=true;
//         for(int i=0;i<isConnected.size();i++){
//             if(isConnected[node][i]==1 && !visited[i]){
//                 dfs(i,isConnected,visited);
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected){
//         int n=isConnected.size();
//         vector<bool> visited(n,false);
//         int count=0;
//         for(int i=0;i<n;i++){
//             if(!visited[i]){
//                 count++;
//                 dfs(i,isConnected,visited);
//             }
//         }
//         return count;
//     }
// };

