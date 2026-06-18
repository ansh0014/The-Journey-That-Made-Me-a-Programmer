// now we are doing the asteroid collision
// i have to understand the question 
// i am understanding hte we have to find the collision of the asteroids 
// this is done by using the stack
// we will previous asteroid and current asteroid and we will check if they are colliding or not
// if they are colliding then we will check which one is bigger and we will pop the smaller one and we will push the bigger one in the stack
// we have to check hte sign of astroid when i got negative sign the prevoius astroids make consider and collid then if value of current astroid is greater than previous astroid then we will pop the previous astroid and we will push the current astroid in the stack
// if the value of current astroid is smaller than previous astroid then we will pop the
// this find previous largest value and we will push the current astroid in the stack
// if the value of current astroid is equal to previous astroid then we will pop the
// now i understand the question when i got positive i have to move in right direction and when i got negative i have to mov in the left collision i have to pop the abosulte smalles no. then sotre in the result vector
// #include <bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     vector<int>asteroidCollision(vector<int> & asteroids){
//         int n=asteroids.size();
//         stack<int>s;
//         for(int i=0;i<n;i++){
//             int curr=asteroids[i];
//             if(curr>0){
//                 s.push(curr);
//             }
//             else{
//                 while(!s.empty() && s.top()>0 && s.top()<abs(curr)){
//                     s.pop();
//                 }
//                 if(!s.empty() && s.top()==abs(curr)){
//                     s.pop();
//                 }
//                 else if(s.empty() || s.top()<0){
//                     s.push(curr);
//                 }
//             }
//         }
//         vector<int> result;
//         while(!s.empty()){
//             result.push_back(s.top());
//             s.pop();
//         }
//         reverse(result.begin(), result.end());
//         return result;
//     }
// };
// now i am doing the remove the K digits 
// i am understanding the question question we have to make smallest interger by removing the k digits 
// so we have to remove the k digits from the number and we have to make the smallest number possible
// we have store the digits form the left side then check the if next no. is small then i have to remove the previous no. and i have to push the next no. in the stack and i have to do this until i remove k digits or i have to check the next no. is small then i have to remove the previous no. and i have to push the next no. in the stack and i have to do this until i remove k digits or i have to check the next no. is small then i have to remove the previous no. and i have to push the next no. in the stack and i have to do this until i remove k digits or i have to check the next no. is small then i have to remove the previous no. and i have to push the next no. in the stack and i have to do this until i remove k digits or i have to check the next no. is small then i have to remove the previous no. and i have to push the next no. in the stack and i have to do this until i remove k digits or i have to check the next no. is small then i have to remove the previous no. and i have to push the next no. in the stack and i have to do this until i remove k digits or
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
string removeKdigits(string num, int k){
    int n=num.size();
    stack<char>s;
    for(int i=0;i<n;i++){
        char curr=num[i];
        while(!s.empty() && s.top()>curr && k>0){
            s.pop();
            k--;
        }
        s.push(curr);
    }
    while(k>0 && !s.empty()){
        s.pop();
        k--;
    }
    string result;
    while(!s.empty()){
        result.push_back(s.top());
        s.pop();
    }
    reverse(result.begin(), result.end());

    int i=0;
    while(i<result.size() && result[i]=='0'){
        i++;
    }
    result=result.substr(i);
    return result.empty()?"0":result;


}
};