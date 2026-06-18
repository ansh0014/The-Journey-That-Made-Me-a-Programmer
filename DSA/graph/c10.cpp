// now i am doing the Surrounded Regions
// i understand the question i have give output of capture region
// capaure region means we have to change the 'O' to 'X' which are surrounded by 'X' and we have to keep the 'O' which are not surrounded by 'X' as it is
// if region is surrounded if none of the 'O' in that region is connected to the boundary of the matrix
// we have to used the bfs to solve ande edge cases when 0 at edge we don't have to cahnbe it
#include <bits/stdc++.h>
using namespace std;

class Solution
{

    void bfs(int i, int j,
             vector<vector<char>> &board,
             vector<vector<int>> &vis)
    {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;

        q.push({i, j});
        vis[i][j] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] &&
                    board[nrow][ncol] == 'O')
                {
                    vis[nrow][ncol] = 1;

                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 'O' && !vis[i][j])
                {
                    bfs(i, j, board, vis);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O' && !vis[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};