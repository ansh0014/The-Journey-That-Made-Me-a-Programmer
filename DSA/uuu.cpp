// now i am doing the parallel courses 11
// i have given an integer n, which indicates that there are n courses labelled from 1 to n. i have also given an array realtions where relations[i]=[prevCourse, nextCoursei] representing a prequisite relationship between course prevCoursei and course nextcoursei. Course prevCousei has to be taken before course nextCoursei. Also, i have given the integer k.
// i one smester i can take at mostk courses as long as i have taken all the prerequisites in the previous semesters for the courses i am taking.
// return the minimum number of smester needed to take all courses . The testcases will generated such that it is possible to take every course.
// we used the topological+bitmask
// instead of indegree we used the mask which means course already taken

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int n;
    vector<int>prreq;
    int bfs(int mask){
        int cantake=0;
        for(int i=0;i<n;i++){
            bool notyettaken=!(mask&(1<<i));
            bool prereqtaken=(mask&prreq[i])==prreq[i];
            if(notyettaken && prereqtaken){
                cantake|=(1<<i);
            }
        }
        return cantake;
    }
int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k){
this->n=n;
prreq.assign(n,0);
for(auto &r:relations){
    int prev=r[0]-1;
    int next=r[1]-1;
    prreq[next]|=(1<<prev);
}
vector<int>dp(1<<n,INT_MAX);
dp[0]=0;
for(int mask=0;mask<(1<<n);mask++){
    if(dp[mask]==INT_MAX) continue;
    int cantake=bfs(mask);
    for(int sub=cantake;sub>0;sub=(sub-1)&cantake){
        if(__builtin_popcount(sub)>k) continue;
        dp[mask|sub]=min(dp[mask|sub],dp[mask]+1);
    }
}
return dp[(1<<n)-1];
}



};