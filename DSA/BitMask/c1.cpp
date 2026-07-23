// now i am doing the students happiness
// There are N ranks and M students. in a class each student has happiness value for the rank in the class he gets. the ith student gets happy [i][j] on getting a ran j. it's ok to not assign a rank to some students(tehy get 0 happiness). At most one student can be assigned to a rank . The total happiness of the assignement can be calculated by adding the happiness value of each student for the rank he gets. Return the maximum total happiness that can be achieved by assigning ranks to students.
// approach i will use bitmask dp to find the maximum total happiness that can be achieved by assigning ranks to students. i will use a dp array to store the maximum total happiness that can be achieved by assigning ranks to students. i will iterate through all the possible combinations of students and ranks and for each combination, i will calculate the total happiness and update the dp array accordingly. finally, i will return the maximum value in the dp array.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxHappiness(vector<vector<int>>& happy){
        int n=happy.size();
        int m=happy[0].size();
        vector<int> dp(1<<n, 0);
        for(int mask=0; mask<(1<<n); mask++){
            int rank= __builtin_popcount(mask);
            if(rank>=m) continue;
            for(int i=0; i<n; i++){
                if(mask&(1<<i)) continue;
                dp[mask|(1<<i)]=max(dp[mask|(1<<i)], dp[mask]+happy[i][rank]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
int main(){
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin>>t;
 while(t--){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> happy(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>happy[i][j];
        }
    }
    Solution sol;
    cout<<sol.maxHappiness(happy)<<"\n";
}
}