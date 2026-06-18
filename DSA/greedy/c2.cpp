// // now i am doing the valid parentheses string
// // this question is also greedy easy () is valid parenthesse * this i have assign the ( then i have to cehck the validation give hte bool fuciton
// #include<bits/stdc++.h>
// using namespace std;
// // this is greedy use the two pointer approach to check the validation
// class Solution{
// public:
// bool checkValidString(string s){
//     int l=0;
//     int r=0;
//     int n=s.size();
//     // we have give return true and false
//     for(int i=0;i<n;i++){
//         if(s[i]=='('){
//             l++;
//         }
//         else if(s[i]=='*'){
//             r++;
//         }
//         else{
//             if(l>0){
//                 l--;
//             }
//             else if(r>0){
//                 r--;
//             }
//             else{
//                 return false;
//             }
//         }

//     }
//     l=0; r=0;
//     for(int i=n-1;i>=0;i--){
//         if(s[i]==')'){
//             l++;
//         }
//         else if(s[i]=='*'){
//             r++;
//         }
//         else{
//             if(l>0){
//                 l--;
//             }
//             else if(r>0){
//                 r--;
//             }
//             else{
//                 return false;
//             }
//         }

//     }
//     return true;

// }
// };
// now i am doing the candy problem
// i am confusiong about the question one how i decide how i decide how many candies i have to give to the child and how i decide the minimum number of candies i have to give to the child
// firs edge case i have to give atleast one candy to each child and then i have to check the condition if the child have more rating than the previous child then i have to give more candies to the child and if the child have less rating than the previous child then i have to give less candies to the child
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int candy(vector<int>& ratings){
    int  n=ratings.size();
int left[n];
int right[n];
for(int i=0;i<n;i++){
    left[i]=1;
    right[i]=1;
}
for(int i=1;i<n;i++){
    if(ratings[i]>ratings[i-1]){
        left[i]=left[i-1]+1;
    }
}
for(int i=n-2;i>=0;i--){
    if(ratings[i]>ratings[i+1]){
        right[i]=right[i+1]+1;
    }
}
int total=0;
for(int i=0;i<n;i++){
    total+=max(left[i],right[i]);
}
return total;
}
};
// the above code is of candy problem i can also do with the monotonic stack but this is also good approach
// and with monotonic previous and next greater element approach also we can do but this is also good approach
// lets do it
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int candy(vector<int>& ratings){
    int n=ratings.size();
    stack<int> st;
    int total=0;
    for(int i=0;i<n;i++){
        while(!st.empty() && ratings[st.top()]<ratings[i]){
            st.pop();
        }
        if(st.empty()){
            total+=1;
        }
        else if(ratings[st.top()]==ratings[i]){
            total+=1;
        }
        else{
            total+=(i-st.top());
        }
        st.push(i);
    }
    return total;
}
};