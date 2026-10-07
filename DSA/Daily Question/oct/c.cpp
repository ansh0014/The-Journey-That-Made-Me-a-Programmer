// now i am doing the divide two integers
// given two integers dividend and divisor, divide two integers without using multiplication division and mod operator.
// the integer division should truncate toward zero, which losing its fractional part . For example 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
// return the quotient after dividing dividend by divisor.
// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the quotient is strictly less than -2^31, then return -2^31.
// i have make formula for this problem and i have used the bit manipulation to solve this problem and i have used the left shift operator to multiply the divisor by 2 and then i have subtracted the dividend by the divisor and then i have added the result to the quotient and then i have returned the quotient.
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
int divide(int dividend, int divisor){
    if(dividend==INT_MIN && divisor==-1) return INT_MAX;
    if(dividend==INT_MIN && divisor==1) return INT_MIN;
    long long d=abs((long long)dividend);
    long long s=abs((long long)divisor);
    long long ans=0;
    while(d>=s){
        long long temp=s;
        long long m=1;
        while(d>=(temp<<1)){
            temp=temp<<1;
            m=m<<1;
        }
        d-=temp;
        ans+=m;
    }
    if((dividend>0 && divisor<0) || (dividend<0 && divisor>0)) ans=-ans;
    return ans;
}
};