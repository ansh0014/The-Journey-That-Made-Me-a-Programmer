// now i am diong the swapping nodes in a linked list
// i understand the quesiton first i have to find swap the nodes from then end then from the start with the given target 
// i used two pointer approach to do the swapping of nodes in a linked list
#include<bits/stdc++.h>
using namespace std;
stuct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
    public:
    ListNode* swapNodes(ListNode* head,int k){
        if(head==NULL )return NULL;
        ListNode* first=head;
        ListNode* second=head;
        for(int i=1; i<k; i++){
            first=first->next;
        }
        ListNode* temp=first;
        while(temp->next!=NULL){
            temp=temp->next;
            second=second->next;
        }
        swap(first->val,second->val);
        return head;
    }
};