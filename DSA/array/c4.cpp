// now i am doing the the skyline problem
// i think this question is combination of sliding window and hashing 
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // i have to make extract form grpha example [[2,9,10],[3,7,15]]
        // output [[2,10],[3,15],[7,0],[9,0]]
        // approach first i have to sort the buildings based on the starting time and then i have
        // we used the comparator function to sort the buildings based on the starting time and if the starting time is same then we have to sort based on the height of the building in descending order
        vector<vector<int>>ans;
        sort(buildings.begin(),buildings.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]){
                return a[2]>b[2];
            }
            return a[0]<b[0];
        });
        // now i have to use the priority queue to store the height of the building and the ending time of the building and then i have to iterate through the buildings and then i have to check if the current building is taller than the previous building then i have to add the current building to the answer and then i have to remove the buildings from the priority queue which are ended before the current building starts
        priority_queue<pair<int,int>>pq;
        int n=buildings.size();
        int i=0;
        while(i<n||!pq.empty()){
            
        }

    }
};