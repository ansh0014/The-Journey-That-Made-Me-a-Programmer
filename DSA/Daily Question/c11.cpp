// now i am doing the maximum Twin sum of linked list
// in a linked list of size n, where n is even , the ith node(0 indexexd) of the linked list is known as the twin of (n-1-i)th node if 0<=i<=(n/2)-1
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int pairSume(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=NULL;
        ListNode* curr=slow;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        int ans=0;
        ListNode* first=head;
        ListNode* second=prev;
        while(second){
            ans=max(ans,first->val+second->val);
            first=first->next;
            second=second->next;
        }
        return ans;

    }
}