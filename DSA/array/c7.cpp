// now i am doing hte array nesting
// i udersnta dhte question s[i] then s[s[i]] then s[s[s[i]]] and so on until we get a loop and we have to return the maximum length of the loop

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int arrayNesting(vector<int>&nums){
        int n=nums.size();
        vector<bool> visited(n,false);
        int maxle=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int count=0;
                int j=i;
                while(!visited[j]){
                    visited[j]=true;
                    j=nums[j];
                    count++;
                }
                maxle=max(maxle,count);
            }
        }        return maxle;
    }
};