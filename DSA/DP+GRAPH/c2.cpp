// now i am doing the parallel Courses 11
// i understand the question
// relation[i]=[prevCoursei, nextCoursei]
// prequisite relationship between course prevCousei and course nextCoursei: course prevCoursei has to be taken before couse nextCoursei also i have given the integer k.
// in one smester, i can take at most k courses as long as the prequisite relationship is satisfied for all the courses taken.
// return the minimum number of semesters needed to take all courses. if it is impossible to take all courses, return -1.
// approach i will use bfs to find the minimum number of semesters needed to take all courses. i will use a queue to store the current course and the number of semesters taken to reach that course. i will also use a set to store the prequisite courses and a set to store the visited courses. i will start from course 1 and keep taking courses until i reach course n or exhaust all possibilities. if i reach course n, i will return the number of semesters taken. if i exhaust all possibilities, i will return -1.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k){
      
    }
};