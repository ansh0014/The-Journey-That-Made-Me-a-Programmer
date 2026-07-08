// now i am doing the modify graph edge weight
// i have given an undirected weighted connected graph conatining n nodes labeled from 0 to n-1 and integer array edges where eges[i]= [ui,vi,weighti] represents a bidirectional and weighted edge between nodes ui and vi with weighti. I have also given an integer array queries where queries[j]=[pj,qj].
// our task to modify all edges with a weight of -1 by assigning them positive interger values int the range[1,2*10^9]so that the shortest distance betwween the nodes soruce and destination becomes equal to an interger target.if there multiple modification that make the shortest distacne between soruce and destiantion equal to target, any of them will be considered correct
// retrun an array coantining all deges(even unmoidified one ) in ay order if tis is possible to amke the shrotes dsitance form soruce to destination equal to target, otherwise return an empty array
// approach first we build the graph using adjacency list then we makethe destination
// issue we have given the edges we have modifiy only -1 edges and we have to make the shortest distance from source to destination equal to target
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    const int INF = 2000000000;

    void dijkstra(int n,
                  vector<vector<pair<int,int>>> &graph,
                  vector<vector<int>> &edges,
                  vector<vector<ll>> &dist,
                  int source,
                  ll diff,
                  int run) {

        priority_queue<pair<ll,int>,
                       vector<pair<ll,int>>,
                       greater<pair<ll,int>>> pq;

        dist[source][run] = 0;
        pq.push({0, source});

        while (!pq.empty()) {

            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u][run])
                continue;

            for (auto &[v, idx] : graph[u]) {

                int w = edges[idx][2];

                if (w == -1)
                    w = 1;

                if (run == 1 && edges[idx][2] == -1) {

                    ll newWeight = diff + dist[v][0] - dist[u][1];

                    if (newWeight > w) {
                        w = (int)newWeight;
                        edges[idx][2] = w;
                    }
                }

                if (dist[u][run] + w < dist[v][run]) {
                    dist[v][run] = dist[u][run] + w;
                    pq.push({dist[v][run], v});
                }
            }
        }
    }

    vector<vector<int>> modifiedGraphEdges(
        int n,
        vector<vector<int>>& edges,
        int source,
        int destination,
        int target) {

        vector<vector<pair<int,int>>> graph(n);

        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], i});
            graph[edges[i][1]].push_back({edges[i][0], i});
        }

        vector<vector<ll>> dist(n, vector<ll>(2, LLONG_MAX));

     
        dijkstra(n, graph, edges, dist, source, 0, 0);

        ll diff = (ll)target - dist[destination][0];

        if (diff < 0)
            return {};


        dijkstra(n, graph, edges, dist, source, diff, 1);

        if (dist[destination][1] != target)
            return {};

        for (auto &e : edges)
            if (e[2] == -1)
                e[2] = 1;

        return edges;
    }
};