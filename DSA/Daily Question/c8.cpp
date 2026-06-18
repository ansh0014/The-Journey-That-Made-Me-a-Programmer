// now we are doing the number of ways to assign edge weight 1
// this is greedy+dfs graph question
// their is undirected tree with n nodes labeled from 1 to n, rooted at node 1. the tree is represented by a 2d integer array edges of length n-1 where edges[i]=[ui,vi]
// intially all edges have weight of 0. you must assign each edge a weight of either 1 or 2
// the cost of a pth between any nodes u and v is the total weight of all edges in the pateh connection tehm 
// select any on node x at the maximum depth.return the number of ways to assign edge weights in the path from node 1 to x such that its toatl cost is odd
// since may be large return it modulo 10^9+7
// greedy approach is to assign weight 1 to all the edges in the path from node 1 to x and assign weight 2 to all the other edges
#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    static const int MOD = 1000000007;

    long long power(long long a,long long b)
    {
        long long ans=1;

        while(b)
        {
            if(b&1)
                ans=(ans*a)%MOD;

            a=(a*a)%MOD;
            b>>=1;
        }

        return ans;
    }

    int assignEdgeWeights(vector<vector<int>>& edges)
    {
        int n=edges.size()+1;

        vector<vector<int>> graph(n+1);

        for(auto &e:edges)
        {
            int u=e[0];
            int v=e[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int maxDepth=0;

        function<void(int,int,int)> dfs =
        [&](int node,int parent,int depth)
        {
            maxDepth=max(maxDepth,depth);

            for(int neighbor:graph[node])
            {
                if(neighbor!=parent)
                {
                    dfs(neighbor,node,depth+1);
                }
            }
        };

        dfs(1,-1,0);

        if(maxDepth==0)
            return 0;

        return power(2,maxDepth-1);
    }
};
