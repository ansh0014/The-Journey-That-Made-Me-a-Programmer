// now we are doing the is graph Bipartite problem
// we used bfs for that
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
bool isBipartite(vector<vector<int>> & graph){
    int n=graph.size();
    vector<int>vistied(n,0);
    for(int i=0;i<n;i++){
        if(vistied[i]) continue;
        vistied[i]=1;
        stack<int> st;
        st.push(i);
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(int neighbour:graph[node]){
                if(!vistied[neighbour]){
                    vistied[neighbour]=-vistied[node];
                    st.push(neighbour);
                }
                else if(vistied[neighbour]==vistied[node]){
                    return false;
                }
            }
        }
    }
    return true;
}
};