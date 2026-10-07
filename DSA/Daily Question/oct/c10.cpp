// now i am doing the remove the invalid parentheses
// i have given a string s that contains parentheses and letters, remvoe the minimum number of invalid parentheses to make the input string 
// return the unique  strings that are valid with the minimum number of removals. i may return the answer in any order.
// one thing i understand i have implement the stackdata structure
// now i have to understand the what i perform the operation on the string and how to remove the invalid parentheses from the string
// we have implement the bfs technique to solve this problem and we have to use the set data structure to store the unique strings that are valid with the minimum number of removals
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isvalid(string s){
        int b=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') b++;
            else if(s[i]==')') b--;
            if(b<0) return false;
        }
        return b==0;
    }
        vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        bool found=false;
        while(!q.empty()){
            string current=q.front();
            q.pop();
            if(isvalid(current)){
                ans.push_back(current);
                found=true;
            }
            if(found) continue;
            for(int i=0;i<current.size();i++){
                if(current[i]=='(' || current[i]==')'){
                    string next=current.substr(0,i)+current.substr(i+1);
                    if(visited.find(next)==visited.end()){
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }
        return ans;
    }
};