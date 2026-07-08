#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minOperations(string s1 ,string s2){
        int n=s1.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]){
                continue;
            }
            if(s1[i]=='0'){
                s1[i]='1';
                ans++;
                continue;
            }
            if(i+1<n && s1[i+1]=='1'){
                s1[i]='0';
                s1[i+1]='0';
                ans++;
                continue;
            }
            if(i-1>=0 && s1[i-1]=='1'){
                s1[i]='0';
                s1[i-1]=s1[i-1];
                ans++;
                if(s2[i-1]=='1'){
                    ans++;
                }
                continue;
            }

               if (i + 1 < n && s1[i + 1] == '0') {

                s1[i] = '0';
                s1[i + 1] = s2[i + 1];

                ans += 2;                   

                if (s2[i + 1] == '1')
                    ans++;              

                continue;
            }
                        if (i - 1 >= 0 && s1[i - 1] == '0') {

                s1[i] = '0';
                s1[i - 1] = s2[i - 1];

                ans += 2;

                if (s2[i - 1] == '1')
                    ans++;

                continue;
            }
        }

        if (s1 != s2)
            return -1;

        return ans;
    }
};