// now i am doing the cut off trees for golf event
// i have to cut off the trees in a forest for a golf event. The forest is represented as an m*n matrix. In this matrix,
// 0 means the cell cannot be walked through,
// 1 reperesents an empty cell that can be walked through,
// A number greate then 1 represents a tree in a cell can be walked through and this number is the tree height.
// in one step, i can walk in any of the four directions north, east, south and west. if you are standing in a cell with a tree , i can choose wheter to cut it off.
// i must cut off the trees in order from shortest to tallest. When i cut of a tree, the value at its cell becomes 1(an empty cell).
// starting from the point (0,0) return the minimum steps to need to walk to cut off the trees i i cannot cut off all the tree return -1
// apporach i have make the bfs then use dp for transtion and then use the bfs to find the shortest path to cut off all the trees in order from shortest to tallest. I will use a priority queue to always cut the shortest tree next.
#include<bits/stdc++.h>
using namespace std;
class Solution{

    int bfs(vector<vector<int>>& forest, int startRow, int startCol, int targetRow, int targetCol) {
        int m = forest.size();
        int n = forest[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        if(startRow== targetRow && startCol==targetCol) return 0;
        queue<pair<int,int>> q;
        q.push({startRow, startCol});
        visited[startRow][startCol] = true;
        int steps = 0;
        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()) {
            int size = q.size();
            steps++;
            for(int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();
                for(auto [dr, dc] : directions) {
                    int newRow = row + dr;
                    int newCol = col + dc;
                    if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol] && forest[newRow][newCol] != 0) {
                        if(newRow == targetRow && newCol == targetCol) return steps;
                        visited[newRow][newCol] = true;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        return -1;
    }
    public:
    int cutOffTree(vector<vector<int>> forest){
        int m = forest.size();
        int n = forest[0].size();
        vector<pair<int,pair<int,int>>> trees;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(forest[i][j] > 1) {
                    trees.push_back({forest[i][j], {i, j}});
                }
            }
        }
        sort(trees.begin(), trees.end());
        int totalSteps = 0;
        int currentRow = 0, currentCol = 0;
        for(auto tree : trees) {
            int targetRow = tree.second.first;
            int targetCol = tree.second.second;
            int steps = bfs(forest, currentRow, currentCol, targetRow, targetCol);
            if(steps == -1) return -1;
            totalSteps += steps;
            currentRow = targetRow;
            currentCol = targetCol;
            // forest[currentRow][currentCol] = 1;
            if(forest[currentRow][currentCol] > 1) {
                forest[currentRow][currentCol] = 1;
            }

        }
        return totalSteps;
    }

};