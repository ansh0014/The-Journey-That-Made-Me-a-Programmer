// now i amd doing the IPO 
// supoose leetcode will start its ipo soon. in order to sell a good price of its share to venture capital, leetoce would like to work on some projects to increase its capital before the IPO.
// Since it has limited resources, it can only finish at most k distinct prjects before the  IPO. help leetcode dsign the best way to maximize its total capital  after finisht at mostk distincet projects.
// i have given n project 
// pure profit[i] and minimum capital of capital[i] is required to start the ith project
// w capital whne i complete i will obtian its pure profit and profit will be added to our total capital
// pick a list of at most k distinct projects from given project to maximiz our final and return the final maximised capital
// approach we used greedy approach
// lets write the psedocode
// i make the vector where i store the capital and profit 

// now i will sort the vector in increasing order of capital
// now we make the priority queue where i will store the profit in decreasing order
// now i will iterate over the vector and check if the capital is less than or equal to

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
       int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
      int n=profits.size();
      int c=capital.size();
      vector<pair<int,int>>v;
      for(int i=0;i<n;i++){
          v.push_back({capital[i],profits[i]});
      }
      sort(v.begin(),v.end());
priority_queue<int>pq;
      int j=0;
      for(int i=0;i<k;i++){
          while(j<n && v[j].first<=w){
              pq.push(v[j].second);
              j++;
          }
          if(!pq.empty()){
              w+=pq.top();
              pq.pop();
          }
      }
      return w;

    }
};

