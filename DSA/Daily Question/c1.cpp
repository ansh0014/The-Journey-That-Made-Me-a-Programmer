// now i am doing the minimum cost of buying candies with the discount
// it is a greedy approach problem
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int sum=0;
        for(int i=0;i<cost.size();i++){
            if((i+1)%3!=0){
                sum+=cost[i];
            }
        }
        return sum;
    }
};