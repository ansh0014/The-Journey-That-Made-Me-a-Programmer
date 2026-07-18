// Minimum Jumps to Reach Home
// A certain bug's homeis on the x-axis at position x. Help them get there from position 0.
// the bug jumps according to the following rules.
// it can jump exactly a positions forward(to the right)
// it can jump exactly b positions backward(to the left)
// it cannot jump backward twice in a row
// it cannot jump to any forbidden positions.
// the bug may jump forward beyond its home , but it cannot jump to positions numbered with negative integers.
// Given any array of integers forbidden, where forbidden[i] means that the bug cannot jump to position forbidden[i]. and integers a, b and x return the minimum number of jumps needed for the bug to reach its home. if there is no possible sequence of jumps that lands the bug on position x, return -1;
// approach i will use bfs to find the minimum jumps to reach home. i will use a queue to store the current position and the number of jumps taken to reach that position. i will also use a set to store the forbidden positions and a set to store the visited positions. i will start from position 0 and keep jumping forward and backward until i reach position x or exhaust all possibilities. if i reach position x, i will return the number of jumps taken. if i exhaust all possibilities, i will return -1.
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int minimumJumps(vector<int>& forbidden, int a, int b, int x){
    queue<tuple<int,int,bool>> q;
    const int LIMIT=6000;
    unordered_set<int> forbiddenSet(forbidden.begin(), forbidden.end());
    vector<vector<bool>> visited(LIMIT+1, vector<bool>(2, false));
    q.push({0, 0, false});
    visited[0][0]=true;
    
    while(!q.empty()){
        auto [pos,jumps, backward]=q.front();
        q.pop();
        if(pos==x) return jumps;
        int forwardPos=pos+a;
        if(forwardPos<=LIMIT && !forbiddenSet.count(forwardPos) && !visited[forwardPos][0]){
            visited[forwardPos][0]=true;
            q.push({forwardPos, jumps+1, false});
        }
        int backwardPos=pos-b;
        if(!backward && backwardPos>=0 && !forbiddenSet.count(backwardPos) && !visited[backwardPos][1]){
            visited[backwardPos][1]=true;
            q.push({backwardPos, jumps+1, true});
        }
    }
    return -1;
}};