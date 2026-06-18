// now i amd doing the greedy
// now i am doing the assign cookies
// this question is done with the greedy approach we have to sort the greed and the size of the cookie and then we have to check the condition if the greed is less than or equal to the size of the cookie then we can count it as a content child and then we have to move to the next greed and the next cookie
// #include<bits/stdc++.h>
// using namespace std;

// class Solution{
// public:
// int findContentChildren(vector<int>& g, vector<int>& s){
//     // first we sort the greed and size of the cookie
//     sort(g.begin(),g.end());
//     sort(s.begin(),s.end());
//     // we use two pointer approach to count the content children
//     int l=0;
//     int r=0;
//     int n=g.size();
//     int m=s.size();
//     while(l<m && r<n){
//         if(s[l]>=g[r]){
//             r++;
//         }
//         l++;
//     } 
//     return r;

// }
// };
// noow i am doing the lemonade change
// this question is greddy approach i understand the problme i have to exchange with 5 dollar bill and 10 dollar bill and then i have to check the condition if the customer is giving 5 dollar bill then i can give the change with 5 dollar bill and if the customer is giving 10 dollar bill then i can give the change with 5 dollar bill and if the customer is giving 20 dollar bill then i can give the change with 10 dollar bill and 5 dollar bill
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// bool lemonadeChange(vector<int>& bills){
//     int n=bills.size();
//     int five=0;
//     int ten=0;
//     for(int i=0;i<n;i++){
//         if(bills[i]==5){
//             five++;
//         }
//         else if(bills[i]==10){
// if(five==0) return false;
//             five--;
//             ten++;
//         }
//         else{
//             if(ten>0 && five >0){
//                 ten--;
//                 five--;
//             }
//             else if(five>=3){
//                 five-=3;
//             }
//             else{
//                 return false;
//             }
//         }
//     }
// return true;
// }
// };
// now i am doing the super washing machine
// first i have to understand the question 
/*
1) i have given the washing machine and the number of dresses in each washing machine  and i have to find minimum number of moves to make all the washing machine have the same number of dresses
2) first edge case if the washing machine have different number of dresses then we can return -1
3) i have to sume the total number of dresses means in array that i have element sum is the dreess
4) then i have to find the average number of dresses in each washing machine means total number of dresses divided by the number of washing machine
5) means lets take example [1,0,5] total is 6 average is not method this is wrong because in explanation 
1st  move 1 1 4
i have to do adjacent move means i have to move the dress from one washing machine to another washing machine mean 1,0,5 means 1<---0<---5 from right divide it answer 1 1 4
then second move 1<--1<---4 measn 2 1 3 
then third move 2<--1<---3 means 2 2 2
apprach in each adjacent move we have to move we use the loop and then we have to check the condition if the current washing machine have more than average then we can move the dress to the next washing machine and if the current washing machine have less than average then we can move the dress from the previous washing machine to the current washing machine
 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int findMinMoves(vector<int>&machines){
    int n=machines.size();
    int total=0;
    for(int i=0;i<n;i++){
        total+=machines[i];
    }
    if(total%n!=0) return -1;
    // we have to take average because we have to move the dress from one washing machine to another washing machine so we can take the average and then we can move the dress from one washing machine to another washing machine
int avg=total/n;
int moves=0;
int count=0;
for(int i=0;i<n;i++){
    count+=machines[i]-avg;
    moves=max(moves,max(abs(count),machines[i]-avg));

}
return moves;
}
};