// now we learn about the set
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void explainSet(){
    set<int>st;
    st.insert(1);   //{1}
    st.insert(2);   //{1,2}
    st.insert(3);   //{1,2,3}
    st.emplace(4);   //{1,2,3,4}
    // add the element in the sorted manner
    // fucntionality of insert in vector
    // can be used also, that only increses efficiency
    // begin(), end(), rbegin(), rend(), size(),
    // empty()
    //  {1,2,3,4,5}
    auto it =st.find(3);
    auto it = st.find(6);
    st.erase(5);   // erase 5
    int cnt=st.count(1);
    auto it =st.find(3);
    st.erase(it);
    auto it1=st.find(2);
    auto it1=st.find(4);

}
int main(){
    return 0;
}
