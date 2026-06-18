// now i am doing the no. of islands
// i uderstadn the question this bfs questio have to traver i return the no. o returns i hav to slect the island which is the 1 then treave i have return maximum no. of the 1 for maximum cover all the the 1
#include <bits/stdc++.h>
using namespace std;
// class Solution
// {
//     void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis)
//     {
//         vis[i][j] = 1;
//         queue<pair<int, int>> q;
//         q.push({i, j});
//         int n = grid.size();
//         int m = grid[0].size();
//         int delrow[] = {-1, 0, 1, 0};
//         int delcol[] = {0, 1, 0, -1};
//         while (!q.empty())
//         {
//             int i = q.front().first;
//             int j = q.front().second;
//             q.pop();
//             // now we traverse in neighbourhood
//             for (int k = 0; k < 4; k++)
//             {
//                 int nrow = i + delrow[k];
//                 int ncol = j + delcol[k];
//                     if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
//                     {
//                         vis[nrow][ncol] = 1;
//                         q.push({nrow, ncol});
//                     }
//                 }
//             }
//         }
    

// public:
//     int numIslands(vector<vector<char>> &grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> vis(n, vector<int>(m, 0));
//         int count = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (!vis[i][j] && grid[i][j] == '1')
//                 {
//                     count++;
//                     bfs(i, j, grid, vis);
//                 }
//             }
//         }
//         return count;
//     }


// };
// now i am doing the flood fill question
class Solution
{
// we have to apply bfs we have to bfs in directly adjacent side erither horizontal or vertical
    void bfs(int i, int j, vector<vector<int>> &image, vector<vector<int>> &vis, int newColor)
    {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        int n = image.size();
        int m = image[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int color = image[i][j];
        image[i][j] = newColor;
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            // now we traverse in neighbourhood
            for (int k = 0; k < 4; k++)
            {
                int nrow = i + delrow[k];
                int ncol = j + delcol[k];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && image[nrow][ncol] == color)
                {
                    vis[nrow][ncol] = 1;
                    image[nrow][ncol] = newColor;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int color = image[sr][sc];
         if (color == newColor){
            return image;
         }
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        bfs(sr, sc, image, vis, newColor);
        return image;
    }
};