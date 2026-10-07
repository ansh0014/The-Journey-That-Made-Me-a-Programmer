// find the first player to win k games in a row
// a competition consits of n players numbered from 0 to n-1.
// i have given an integer array skills of size n and a positive integer k, where skills[i] is the skill level of player i. All integers ink skills are unique.
// a player wins are standing in a queue in order from player 0 to player n-1.
// the competition process is as follows:

// the first two players in the queue play a game, and the player with the higher skill level wins
// after a game, the winner remains at the beginning of the queue, and the loser goes to the end of it.
// the winner of the competition is the first player who wins k games in a row.

// now we used the sliding window technique to find the first player to win k games in a row
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int findWinningPlayer(vector<int>& skills, int k){
        int n = skills.size();
    
     
        int currentwinner = 0;
        int currentwins = 0;
    for(int right = 1; right < n; right++){
        if(skills[right] > skills[currentwinner]){
            currentwinner = right;
            currentwins = 1;
        }else{
            currentwins++;
        }
        if(currentwins == k){
            return currentwinner;
        }
    }
    return currentwinner;
        }

};