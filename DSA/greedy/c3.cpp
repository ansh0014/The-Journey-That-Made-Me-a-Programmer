// now i am doing the jump game
// this is greedy question i have to use the two pointer approach to solve this question
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     bool canJump(vector<int>& nums){
//         int n=nums.size();
//         int maxreach=0;
//         for(int i=0;i<n;i++){
//             if(i>maxreach) return false;
//             maxreach=max(maxreach,i+nums[i]);

//         }
//         return true;
        
//     }
// };
// now i am doing the JUMP GAME II
// i am little bit confused ik greedy approach work 
// in example they given [2,3,1,1,4] output is 2
// but 2 jumpts to 3 and 1 and 1 jump to 1 1 to 4 so total jump is 2
// how the total jump is 2 i am little bit confused
// ok i understand the question means at index 0 i can jump at index 1 and 2 so my range is [1,2] at index there there is 3 so i can jump at index 2,3 and 4 so my range is [2,3,4] at index 2 there is 1 so i can jump at index 3 and at index 3 there is 1 so i can jump at index 4 so total jump is 2
#include<bits/stdc++.h>
using namespace std;
class Solution{
int jump(vector<int>&nums){
    // this is greedy approach
    // but i cand do greedy + two pointer

    int n=nums.size();
    int jumps=0;
    int currentEnd=0;
    int farthest=0;
    for(int i=0;i<n-1;i++){
        farthest=max(farthest,i+nums[i]);
        if(i==currentEnd){
            jumps++;
            currentEnd=farthest;
        }


    }
    return jumps;
}
};