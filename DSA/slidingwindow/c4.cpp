// now i am doing the word ladder
// a transformation sequence form word begifnword to word end word using a dictionary word list is a swquence of words beginwords-->s1-->s2--->...--->sk
// such that
// every adjacent pari of word differs by signle letter 
// every si for i<=i<=k is wordlist . Notes that begin word does not need to be in wordlist.
// sk==endword
// given two words, beginword and endword and dictionary wordlsit return the number of words in the shortest tranformation sequence from bein word to endword or 0 if not such squence exists
// we usid make hasp map then used  condition to check the word ladder and then used bfs to find the shortest path
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int bfs(string beginWord, string endWord, unordered_map<string,int> &mp){
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;
        pq.push({1, beginWord});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            string word=it.second;
            int steps=it.first;
            if(word==endWord){
                return steps;
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(mp.find(word)!=mp.end()){
                        pq.push({steps+1,word});
                        mp.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    int n=wordList.size();
    unordered_map<string, int> mp;
    for(int i=0;i<n;i++){
        mp[wordList[i]]=1;
    }
    if(mp.find(endWord)==mp.end()){
        return 0;
    }
    return bfs(beginWord, endWord, mp);

    

}
};