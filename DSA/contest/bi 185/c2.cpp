// now i am doing the finish Time of Taks 1
// i have given an interger n representing the number of tasks in a porject numbered form 0 to n-1. these taks are connected as a tree rooted at task 0. this is represented by a 2d integer array edges of lenght n-1, where edges[i]=[ui,vi] indicates that task ui is the parent of task vi
// i have also given an array baseTime of lenght n where baseTime[i] represents the time to complete task i
// the finish time of each task is calculate as follows:
// leaf task: the finish time is baseTime[i].
// non-leaf task:
// let earliest be the minimum finish time among its children and latest be the maximum finish time among its children.
// let ownduration be (latest-earliest)+baseTime[i].
// retrun the finish of the root task 0.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long timeTaken(vector<vector<int>>& edges, vector<int>& baseTime) {
        int n = baseTime.size();
        vector<vector<int>> children(n);
        for (auto &e : edges) children[e[0]].push_back(e[1]);

        vector<int> order;
        order.reserve(n);
        vector<int> q = {0};
        for (int head = 0; head < (int)q.size(); head++) {
            int u = q[head];
            order.push_back(u);
            for (int v : children[u]) q.push_back(v);
        }

        vector<long long> finish(n, 0);
        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int u = order[i];
            if (children[u].empty()) {
                finish[u] = baseTime[u];
            } else {
                long long earliest = LLONG_MAX, latest = LLONG_MIN;
                for (int v : children[u]) {
                    earliest = min(earliest, finish[v]);
                    latest = max(latest, finish[v]);
                }
                long long ownDuration = (latest - earliest) + baseTime[u];
                finish[u] = latest + ownDuration;
            }
        }
        return finish[0];
    }
};