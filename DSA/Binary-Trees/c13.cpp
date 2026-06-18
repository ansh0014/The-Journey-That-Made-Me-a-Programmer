// now i am doing the Kth Ancestor of a Tree Node
// we used binary lifting to solve this
#include <bits/stdc++.h>
using namespace std;

class TreeAncestor
{
public:
    int LOG;
    vector<vector<int>> up;
    vector<int> depth;
    int getDepth(int node, vector<int> &parent)
    {
        if (depth[node] != -1)
            return depth[node];
        if (parent[node] == -1)
            return depth[node] = 0;
        return depth[node] = getDepth(parent[node], parent) + 1;
    }

    TreeAncestor(int n, vector<int> &parent)
    {

        LOG = 0;
        while ((1 << LOG) <= n)
            LOG++;
        up = vector<vector<int>>(n, vector<int>(LOG, -1));
        depth = vector<int>(n, -1);

        for (int v = 0; v < n; v++)
        {
            getDepth(v, parent);
        }

        for (int v = 1; v < n; v++)
        {
            up[v][0] = parent[v];
            depth[v] = depth[parent[v]] + 1;
        }

        for (int j = 1; j < LOG; j++)
        {
            for (int v = 0; v < n; v++)
            {

                if (up[v][j - 1] == -1)
                    up[v][j] = -1;
                else
                    up[v][j] = up[up[v][j - 1]][j - 1];
            }
        }
    }

    int getKthAncestor(int node, int k)
    {

        if (depth[node] < k)
            return -1;

        for (int j = 0; j < LOG; j++)
        {
            if (k & (1 << j))
            {
                node = up[node][j];
            }
        }

        return node;
    }
};
