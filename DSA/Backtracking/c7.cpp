// now i am doing the pacific atlantic water flow
// given an m*n matrix of non-negative integers representing the height of each unit cell in a continent, the "pacific ocean" touches the left and top edges of the matrix and the "atlantic ocean" touches the right and bottom edges.
// water can only flow in four directions (up, down, left, or right) from
// we can use backtracking to find the cells that can flow to both the pacific and atlantic oceans. we will start from each cell and check if we can reach both oceans by moving in the four directions. we will use a visited matrix to keep track of the cells that have already been visited to avoid cycles. finally, we will return the list of cells that can flow to both oceans.
#include<bits/stdc++.h>
using namespace std;
class Solution {
          void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j) {
            visited[i][j] = true;
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto& dir : directions) {
                int x = i + dir.first;
                int y = j + dir.second;
                if (x >= 0 && x < heights.size() && y >= 0 && y < heights[0].size() && !visited[x][y] && heights[x][y] >= heights[i][j]) {
                    dfs(heights, visited, x, y);
                }
            }
        }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        if (m == 0) return {};
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
  
    }
};