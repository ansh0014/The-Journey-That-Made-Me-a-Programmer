// now i am doing the number of ways to assign edge weights 11
// i think we have do that use segment tree and we have to do that for each node at the maximum depth



#include <bits/stdc++.h>
using namespace std;
class Solution{
    // intitution
    // first we build graph
    // dfs from root =1
    // depth
    // update max depth
    // pow2[i]=pow(2,i) mod 10^9+7
public:
// first we make the graph
static const int MOD=1000000007;
long long power(long long a, long long b){
    long long ans=1;
    while(b){
        if(b&1)
        ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries){
int n=edges.size()+1;
vector<vector<int>>graph(n+1);
for(auto &e:edges){
    int u=e[0];
    int v=e[1];
    graph[u].push_back(v);
    graph[v].push_back(u);

}
int maxdepth=0;
function<void(int ,int ,int)>dfs=[&](int node,int parent,int depth){
    maxdepth=max(maxdepth,depth);
    for(int neighbor:graph[node]){
        if(neighbor!=parent){
            dfs(neighbor,node,depth+1);
        }
    }
};
dfs(1,-1,0);
if(maxdepth==0){
return vector<int>(queries.size(),1);


    }
}
};