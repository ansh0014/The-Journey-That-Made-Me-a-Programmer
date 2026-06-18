// now i am doing the question of detect the cycle by the bfs
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     private:
//     bool bfs(int i ,vector<int> adj[], int vis[]){
//         vis[i]=1;
//         queue<pair<int,int>> q;
//         q.push({i,-1});
//         while(!q.empty()){
//             int node=q.front().first;
//             int parent=q.front().second;
//             q.pop();
//             for(auto it:adj[node]){
//                 if(!vis[it]){
//                     vis[it]=1;
//                     q.push({it,node});
//                 }
//                 else if(parent!=it){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
//     public:
//     bool isCycle(int V, vector<int> adj[]){
//         int vis[V]={0};
//         for(int i=0;i<V;i++){
//             if(!vis[i]){
//                 if(bfs(i,adj,vis)){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }

// };
// now i am doing the 01 matrix
// i seems i have to apply bfs here also
// i have add the distance in the queue also so that we can update the distance of the adjacent nodes
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat){
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int dis=q.front().second;
        q.pop();
        dist[row][col]=dis;
        for(int i=0;i<4;i++){   
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol},dis+1});
            }
        }
    }
    return dist;
}
};
