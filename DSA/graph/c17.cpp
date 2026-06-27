// now i am doing the Shortest Path in Binary Matrix
// i have given the n*n binary matrix grid , return the length of shortest clear path in the matrix
// A clear path in a binary matrix is a path form the top-left cell(i.e.,(0,0)) to the bottom-right cell(i.e.,(n-1,n-1)) such that
// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected(i.e., they are different and they share an edge or a corner).
// the length of a clear path is the number of visited cells of this path
// we used the priority queue for that and we have to find the length of shortest clear path in the matrix
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        {
            return -1;
        }
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            pq;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;
        pq.push({1, 0});
        while (!pq.empty())
        {

            auto [d, node] = pq.top();
            pq.pop();
            int x = node / n;
            int y = node % n;
            if (d > dist[x][y])
            {
                continue;
            }
            for (auto dir : directions)
            {
                int newX = x + dir.first;
                int newY = y + dir.second;
                if (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 0)
                {
                    if (dist[x][y] + 1 < dist[newX][newY])
                    {
                        dist[newX][newY] = dist[x][y] + 1;
                        pq.push({dist[newX][newY], newX * n + newY});
                    }
                }
            }
        }
        return dist[n - 1][n - 1] == 1e9 ? -1 : dist[n - 1][n - 1];
    }
};