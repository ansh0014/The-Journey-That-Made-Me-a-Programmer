// now i am doing the network recovery pathways
// i have graph wiht ui,vi costi indicates a one-way communication form node ui to node vi with a recover cost of costi
// ok lets start some nodes be offline. you are given a boolean array online where online[i]=true means node i is online. nodes 0 and n-1 are always online
// a path from 0 to n-1 is valid if
// all intermediate nodes on the path are online.
// the total recovery cost of all edges on the path does not exceed k
// for each vslid path , define its score as the minimum edge-cost  along that path.
// return the maximum path score (i.e. the largest minimum-edge cost) among all valid paths. if no valid path exists return -1.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool check(int limit,
               vector<vector<pair<int,int>>>& adj,
               vector<int>& topo,
               vector<bool>& online,
               long long k)
    {
        int n = adj.size();

        vector<long long> dp(n, LLONG_MAX);
        dp[0] = 0;

        for (int u : topo)
        {
            if (dp[u] == LLONG_MAX)
                continue;

            if (u != 0 && u != n - 1 && !online[u])
                continue;

            for (auto &[v, w] : adj[u])
            {
                if (w < limit)
                    continue;

                if (v != n - 1 && !online[v])
                    continue;

                dp[v] = min(dp[v], dp[u] + w);
            }
        }

        return dp[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k)
    {
        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indeg(n,0);

        int mx = 0;

        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v,w});
            indeg[v]++;

            mx = max(mx,w);
        }


        queue<int> q;

        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }

        vector<int> topo;

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for(auto &[v,w] : adj[u])
            {
                indeg[v]--;

                if(indeg[v]==0)
                    q.push(v);
            }
        }

        int low = 0;
        int high = mx;
        int ans = -1;

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            if(check(mid,adj,topo,online,k))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};