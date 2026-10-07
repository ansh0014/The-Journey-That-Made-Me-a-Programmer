// ṇow i am doing the if there is valid path in a grid
/*
You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:

1 which means a street connecting the left cell and the right cell.
2 which means a street connecting the upper cell and the lower cell.
3 which means a street connecting the left cell and the lower cell.
4 which means a street connecting the right cell and the lower cell.
5 which means a street connecting the left cell and the upper cell.
6 which means a street connecting the right cell and the upper cell.
*/
// appraoch we use bfs to traverse the grid and check if there is a valid path from the top-left cell to the bottom-right cell. We will use a queue to store the cells to be visited and a set to store the visited cells. We will start from the top-left cell and add it to the queue. Then we will pop a cell from the queue and check its neighbors. If a neighbor is valid and not visited, we will add it to the queue and mark it as visited. We will continue this process until we reach the bottom-right cell or the queue is empty. If we reach the bottom-right cell, we return true, otherwise we return false.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void get(int t, vector<pair<int, int>> &nb)
    {
        switch (t)
        {
        case 1:
            nb = {{0, -1}, {0, 1}};
            break;

        case 2:
            nb = {{-1, 0}, {1, 0}};
            break;

        case 3:
            nb = {{0, -1}, {1, 0}};
            break;

        case 4:
            nb = {{0, 1}, {1, 0}};
            break;

        case 5:
            nb = {{0, -1}, {-1, 0}};
            break;

        case 6:
            nb = {{0, 1}, {-1, 0}};
            break;
        }
    }

    bool valid(int t, int nt, int dx, int dy)
    {

        if (t == 1)
        {
            return (dx == 0 && dy == -1 &&
                    (nt == 1 || nt == 4 || nt == 6)) ||

                   (dx == 0 && dy == 1 &&
                    (nt == 1 || nt == 3 || nt == 5));
        }
        if (t == 2)
        {
            return (dx == -1 && dy == 0 &&
                    (nt == 2 || nt == 3 || nt == 4)) ||

                   (dx == 1 && dy == 0 &&
                    (nt == 2 || nt == 5 || nt == 6));
        }

        if (t == 3)
        {
            return (dx == 0 && dy == -1 &&
                    (nt == 1 || nt == 4 || nt == 6)) ||

                   (dx == 1 && dy == 0 &&
                    (nt == 2 || nt == 5 || nt == 6));
        }

        if (t == 4)
        {
            return (dx == 0 && dy == 1 &&
                    (nt == 1 || nt == 3 || nt == 5)) ||

                   (dx == 1 && dy == 0 &&
                    (nt == 2 || nt == 5 || nt == 6));
        }

        if (t == 5)
        {
            return (dx == -1 && dy == 0 &&
                    (nt == 2 || nt == 3 || nt == 4)) ||

                   (dx == 0 && dy == -1 &&
                    (nt == 1 || nt == 4 || nt == 6));
        }

        if (t == 6)
        {
            return (dx == -1 && dy == 0 &&
                    (nt == 2 || nt == 3 || nt == 4)) ||

                   (dx == 0 && dy == 1 &&
                    (nt == 1 || nt == 3 || nt == 5));
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        queue<pair<int, int>> q;

        q.push({0, 0});
        vis[0][0] = true;

        while (!q.empty())
        {

            auto [x, y] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1)
                return true;

            vector<pair<int, int>> nb;

            get(grid[x][y], nb);

            for (auto [dx, dy] : nb)
            {

                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < m &&
                    ny >= 0 && ny < n &&
                    !vis[nx][ny] &&
                    valid(grid[x][y], grid[nx][ny], dx, dy))
                {

                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
};