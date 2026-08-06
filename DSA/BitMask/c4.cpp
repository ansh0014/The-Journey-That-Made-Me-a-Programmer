// now i am doing the question on maxiumum compatibitly score sume
// i have given m students from 0 to m-1 and mentors m from o to m-1
// each student will be assigned to one mentor and each mentor will have one student assigned to them. 
// the compatibility score of a student-mentor pair is the number of anwers that are same for both thesudent and mentor
// example student [1,0,1] menter [0,0,1] answer si compatibility is 2
// the maximum compatibility score sum is the sum of the compatibility scores of each student-mentor pair in the assignment
// return the maximum compatibility score sum that can be achieved by any possible student-mentor pair assignment
// approach i am using
// i am using bitmask for mask hte no. each student and mentor 
// now question arise whose i mask i think i have mask student to mentor and then i will use the dp for the transition of the mask and then i will use the backtracking to find the maximum compatibility score sum that can be achieved by any possible student-mentor pair assignment
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int dfs(int mask, int i, vector<vector<int>>& students, vector<vector<int>>& mentors, vector<vector<int>>& dp){
        if(i==students.size()) return 0;
        if(dp[mask][i]!=-1) return dp[mask][i];
        int ans=0;
        for(int j=0;j<mentors.size();j++){
            if(mask&(1<<j)) continue;
            int score=0;
            for(int k=0;k<students[i].size();k++){
                if(students[i][k]==mentors[j][k]) score++;
            }
            ans=max(ans,score+dfs(mask|(1<<j),i+1,students,mentors,dp));
        }
        return dp[mask][i]=ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors){
        int m=students.size();
        int n=mentors.size();
        vector<vector<int>> dp(1<<n,vector<int>(m,-1));
        return dfs(0,0,students,mentors,dp);
    
    }
};
