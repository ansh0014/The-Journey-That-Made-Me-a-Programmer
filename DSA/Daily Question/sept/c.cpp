// now i am doing minimum oves to clean the class romm
// i have givne an m*n grid classroom where a student volunteer is tasked with cleanung up litter scattered around the room. each cell in the grid is one of the following
// 'S' starting poistion of the student
/* 'L' litter that must be collected (once collected, the cell becomes empty)
'R' Reset area that restors the student's energy to full capacity, regardless of their current energy level
// 'x' obstacle the student cannot pass through
'.' empty space
 */
// i also given aninteger energy repsenting the student's maximum enery capacity. Th student starts with thsi energy from the starting psition's'
// Each move to an adjcaent cell (up,donw , elft or tight) costs 1 unit of enregy. if the nergy reaches 0, the student can only contuner if they are on rest are'R' which restes the enrgy to its maximum capcity energy
// return the minimum number of moves required to collect all litter itmens or -1 if it's impossible
// now i have to understand the problem
// i have given the m*n means i have implement the bfs approach to solve this problem. i have to keep track of the current position of the student, the current energy level, and the number of litter items collected so far. i will use a queue to perform the bfs and a set to keep track of the visited states. each state will be represented by a tuple of (current position, current energy level, number of litter items collected). i will also keep track of the minimum number of moves required to collect all litter items. if i reach a state where all litter items are collected, i will update the minimum number of moves required. if i exhaust all possible states and cannot collect all litter items, i will return -1.
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minMoves(vector<string> &classroom, int energy)
    {
        int n = classroom.size();
        int m = classroom[0].size();
        vector<pair<int, int>> l;
        pair<int, int> start;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (classroom[i][j] == 'S')
                {
                    start = {i, j};
                }
                else if (classroom[i][j] == 'L')
                {
                    l.push_back({i, j});
                }
            }
        }
        int ll = l.size();
        if (ll == 0)
        {
            return 0;
        }
        vector<vector<int>> lt(n, vector<int>(m, -1));
        for (int i = 0; i < ll; i++)
        {
            auto [x, y] = l[i];
            lt[x][y] = i;
        }
        int total = 1 << ll;
        vector<vector<vector<vector<int>>>> dist(n, vector<vector<vector<int>>>(
                                                        m,
                                                        vector<vector<int>>(
                                                            energy + 1,
                                                            vector<int>(total, -1))));
        queue<tuple<int, int, int, int>> q;
        int x = start.first;
        int y = start.second;
        dist[x][y][energy][0] = 0;
        q.push({x, y, energy, 0});
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()){
            auto [x, y, e, mask] = q.front();
            q.pop();
            int moves = dist[x][y][e][mask];
            if (mask == total - 1)
            {
                return moves;
            }
            if(e==0) continue;
            for(auto [dx, dy] : dirs)
            {
                int nx = x + dx;
                int ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || classroom[nx][ny] == 'X')
                {
                    continue;
                }
                int ne = e - 1;
                if (classroom[nx][ny] == 'R')
                {
                    ne = energy;
                }
                int nmask = mask;
                if (classroom[nx][ny] == 'L') {

                    int id =lt[nx][ny];

                    nmask |= (1 << id);
                }
    if (dist[nx][ny][ne][nmask] != -1) {
                    continue;
                }
                dist[nx][ny][ne][nmask] = moves + 1;
                q.push({nx, ny, ne, nmask});
            }

        }   
        return -1;                                                
    }
};
