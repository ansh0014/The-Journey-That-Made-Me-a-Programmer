#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent;

    public:

    DisjointSet(int n){
        rank.resize(n,0);
        parent.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findUpar(int node){
        if(node==parent[node]){
            return node;
        }

        return parent[node]=findUpar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);

        if(ulp_u==ulp_v){
            return;
        }

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution{
    public:

    int spanningTree(int V, vector<vector<int>> adj[]){

        // {weight,{u,v}}
        vector<pair<int,pair<int,int>>> edges;

        // converting adjacency list into edge list
        for(int i=0;i<V;i++){

            for(auto it: adj[i]){

                int adjNode=it[0];
                int wt=it[1];

                edges.push_back({wt,{i,adjNode}});
            }
        }

        // sort according to weight
        sort(edges.begin(),edges.end());

        DisjointSet ds(V);

        int mstWeight=0;

        for(auto it: edges){

            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;

            // if they belong to different components
            if(ds.findUpar(u) != ds.findUpar(v)){

                mstWeight += wt;

                ds.unionByRank(u,v);
            }
        }

        return mstWeight;
    }
};

int main(){

    int V=3;

    vector<vector<int>> adj[V];

    adj[0].push_back({1,5});
    adj[1].push_back({0,5});

    adj[1].push_back({2,3});
    adj[2].push_back({1,3});

    adj[0].push_back({2,1});
    adj[2].push_back({0,1});

    Solution obj;

    cout << obj.spanningTree(V,adj);

    return 0;
}