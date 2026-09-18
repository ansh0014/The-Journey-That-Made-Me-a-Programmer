// now i am doing the count commas in range
// i have given a integer return the total number of commas in the range from 1 to n
// formatting
// a comma is inserted after every three digiits from the right 
// a numbers with fewer than four digits do not contain any commas
// appraoch we used queue to store the number of commas in the range from 1 to n
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
      int countCommas(int n) {
     int count=0;
     queue<int>q;
     for(int i=1;i<=n;i++){
         if(i>=1000){
             count++;
         }
     }
    while(!q.empty()){
        count+=q.front();
        q.pop();
        if(count>=1000){
            q.push(count/1000);
        }
        else{
            break;
        }
    

    }
    return count;
   
    }
};