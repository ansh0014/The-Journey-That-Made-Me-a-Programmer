// now i am doing the find the minimum and maximum number of nodes between critical points

// a critical point in a linked list is defined as either a local maxima or a local minima.
// a node is a local maxima if the current nod has a value strictly greater than the previous node and the next node
// a node is local minima if the current node has a value strictly less than the previous node and the next node
// approach we used slow and fast pointer to find the critical points in the linked list.
// the we find the critical points and store them in a vector. then we find the minimum and maximum distance between the critical points and return them in a vector. if there are less than 2 critical points, we return {-1,-1}.

#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
     ListNode* slow=head;
    ListNode* fast=head->next;
    vector<int>cp;
    int index=1;
    while(fast!=NULL && fast->next!=NULL){
        if((fast->val>slow->val && fast->val>fast->next->val) || (fast->val<slow->val && fast->val<fast->next->val)){
            cp.push_back(index);
        }
        slow=slow->next;
        fast=fast->next;
        index++;

     
        
    }
    if(cp.size()<2) return {-1,-1};
 int mindist=INT_MAX;
    int maxdist=cp.back()-cp.front();
    for(int i=1;i<cp.size();i++){
        mindist=min(mindist,cp[i]-cp[i-1]);
    }
    return {mindist,maxdist};
    }


};

