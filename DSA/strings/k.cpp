// now i am doing the multiply strings
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string multiply(string num1, string num2){
        int n=num1.size();
        int m=num2.size();
    // if their is leading zero then we have to return zero 
    // approach we can converte the string into number and then multiply 
    // for prevent overflow we can use long long 
    // it work constriant only 200
// i now work 
// we can use the approach of multiplication of two number
// but if num1="0" and num="0" then answer is "0"
 vector<int> ans(n+m,0);
 for(int i=n-1;i>=0;i--){
     for(int j=m-1;j>=0;j--){
         int mul=(num1[i]-'0')*(num2[j]-'0');
         int sum=mul+ans[i+j+1];
         ans[i+j+1]=sum%10;
         ans[i+j]+=sum/10;
     }
 }
    string res="";
    for(int i=0;i<ans.size();i++){
        if(!(res.size()==0 && ans[i]==0)){
            res.push_back(ans[i]+'0');
        }
    }
    return res.size()==0?"0":res;

}
};