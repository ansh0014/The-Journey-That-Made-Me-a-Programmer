// now i am doing he digit frequency score
// i have given the integer n 
// teh score of n is definedn the sum of d*f(d) where d is a digit and f(d) is the frequency of d in n
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     int digitFrequencyScore(int n){
//         // code here
//         int freq[10]={0};
//         while(n>0){
//             int d=n%10;
//             freq[d]++;
//             n/=10;
//         }
//         int score=0;
//         for(int i=0;i<10;i++){
//             score+=i*freq[i];
//         }
//         return score;
//     }
// }
// maximum Number of items from a sale 1
// 2d arreay itemns[i]=[factori, pricei] represents ith itemn
// i have given budget integer budget
// i can buy any number of copies of any items such that the total cost of the purchased copies is at most budget
// rules
// for each item i i bought at least one copy i receive one free copy of every item such j!=i factori divides factorj
// buying multiple copies of teh same item i does not give additon free cpoies throught item i
// the same item j can be received multiple tiems for free if it is received form purchase of different itme types
// return total number of item cpoies i can obtain including both purchased and free copies
// items =[[6,2],[2,6],[3,4]] , budget =9
// output=4 
// approach i think we have to dp knapsack problem

