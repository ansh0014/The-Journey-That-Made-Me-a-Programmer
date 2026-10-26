// now i am doing the prime subset selection 1
// i have given tow integers n and s.
// consider all prime numbers less than or equal to n. Select some of these primes such that:
// the sum of the selected primes is less than or equal to s.
// the number of slected primes is maximized.
// each prime can be selected at most once.
// returh the integer array containing the selected primes in increaing order. if multiple optimila selection exist return any of them.
// if no prime ncan be selected return an empty array.
// we used the simple greedy approach to solve this problem. we will iterate through all the prime numbers less than or equal to n and we will keep adding them to the sum until the sum is less than or equal to s. if the sum is greater than s then we will break the loop and return the selected primes.
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
vector<int>maxPrimes(int n,int s){
    
    vector<int>primes;
    vector<bool>isPrime(n+1,true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
    vector<int>ans;
    int sum=0;
    for(int i=0;i<primes.size();i++){
        if(sum+primes[i]<=s){
            sum+=primes[i];
            ans.push_back(primes[i]);
        }else{
            break;
        }
    }
    return ans;
}
}; 

 
