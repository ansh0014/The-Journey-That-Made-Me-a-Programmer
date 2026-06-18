// now i am doing the strong password checker

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:

int strongPasswordChecker(string password){
    int n=password.size();
    bool hasLower=false;
    bool hasUpper=false;
    bool hasDigit=false;
    for( int i=0;i<n;i++){
        if(islower(password[i])){
            hasLower=true;
        }
        if(isupper(password[i])){
            hasUpper=true;
        }
        if(isdigit(password[i])){
            hasDigit=true;
        }
        
    }
    int missitypes=0;
    if(!hasLower) missitypes++;
    if(!hasUpper) missitypes++;
    if(!hasDigit) missitypes++;
    vector<int> grps;
    int replace=0;
    for(int i=0;i<n;){
        int j=i;
        while(j<n && password[i]==password[j]){j++;}
        int len=j-i;
        if(len>=3){
            grps.push_back(len);
            replace+=len/3;
        }
        i=j;
    }
    // if lenght is less than 6
    if(n<6){
        return max(missitypes,6-n);
    }
    // if length is between 6 and 20
    else if(n<=20){
        return max(missitypes,replace);
    }
    // if length is greater than 20
    int h=grps.size();
    int deleteCount=n-20;
    int remainingDelete=deleteCount;
    for(int i=0;i<h && remainingDelete>0;i++){
        if(grps[i]%3==0){
            grps[i]--;
            remainingDelete--;
            replace--;
        } 
}
for(int i=0;i<h && remainingDelete>1;i++){
    if(grps[i]%3==1){
        int need=min(2,remainingDelete);
        if(need==2){
            grps[i]-=2;
            remainingDelete-=2;
            replace--;
    }
}
}
for(int i=0;i<h && remainingDelete>0;i++){
    if(grps[i]>3){
        int need=grps[i]-2;
        int used=min(need,remainingDelete);
        grps[i]-=used;
        remainingDelete-=used;
        replace-=used/3;
    }
}
return deleteCount+max(missitypes,replace);
}
};
