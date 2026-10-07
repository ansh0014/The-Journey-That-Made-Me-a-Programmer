// now i am doing the validate the IP address
// string a string queryIP return IPV4 IF IP IS a valid address IPV6 if ip is valid IPV6 address or neither if ip is not a correct ip of any type.
// a valid ipv4 address is an ip in the form x1.x2.x3.x4 where 0<=xi<=225 and xi cannot contain leading zeros. Fdor example, :192.168.1.1"and "192.168.1.0" are valid ipvr address while "192.168.1.01" "192.168.1.00" are not.
// a valid ipv6 address is an ip in the form x1:x2:x3:x4:x5:x6:x7:x8 where 1<=xi<=4 is a hexadecimal string which may contain digits,lowercase english letter from 'a' to 'f' and uppercase english letter from 'A' to 'F'. leading zeros are allowed in xi. for example "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid ipv6 address while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are not valid ipv6 address.
// logical i have to think i have to check the string if it is ipv4 and ipv6 or neither and i have to check the string if it is ipv4 then i have to check the string if it is ipv6 then i have to check the string if it is neither then i have to return neither.
// for that we used the split function to split the string by '.' and ':' and then we have to check the length of the split string if it is 4 then it is ipv4 if it is 8 then it is ipv6 if it is neither then we have to return neither.
#include <bits/stdc++.h>
// for spliting we used the stringstream and then we have to check the length of the split string if it is 4 then it is ipv4 if it is 8 then it is ipv6 if it is neither then we have to return neither.
using namespace std;
class Solution{
    public:
    string validIPAddress(string queryIP){
    if(queryIP.find('.')!=string::npos&&queryIP.find(':')!=string::npos){
        return "Neither";
    }
    if(queryIP.find('.')!=string::npos){
        if(queryIP.front()=='.'||queryIP.back()=='.'){
            return "Neither";
        }
        stringstream ss(queryIP);
        string temp;
        vector<string> v;
        while(getline(ss,temp,'.')){
            v.push_back(temp);
        }
        if(v.size()!=4){
            return "Neither";
        }
        for(auto x:v){
            if(x.empty()||x.size()>3||x.size()>1&&x[0]=='0'){
                return "Neither";
            }
            for(auto y:x){
                if(!isdigit(y)){
                    return "Neither";
                }
            }
            if(x.size()>1&&x[0]=='0'){
                return "Neither";
            }
            if(stoi(x)>255){
                return "Neither";
            }
            
        }
        return "IPv4";
    }
    if(queryIP.find(':')!=string::npos){
        if(queryIP.front()==':'||queryIP.back()==':'){
            return "Neither";
        }
        stringstream ss(queryIP);
        string temp;
        vector<string> v;
        while(getline(ss,temp,':')){
            v.push_back(temp);
        }
        if(v.size()!=8){
            return "Neither";
        }
        for(auto x:v){
            if(x.empty()||x.size()>4){
                return "Neither";
            }
            for(auto y:x){
                if(!isdigit(y)&&!(y>='a'&&y<='f')&&!(y>='A'&&y<='F')){
                    return "Neither";
                }
            }
        }
        return "IPv6";
    }
    return "Neither";
    }
};