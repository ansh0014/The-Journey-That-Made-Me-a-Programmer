// now i am doing teh delete the middle node of a linked list
// approach we used fast and slow pointer and when fast pointer reaches the end of the linked list then slow pointer will be at the middle node and we will delete that node
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    ListNode* deleteMiddle(ListNode* head){
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow==head){
            return NULL;
        }
        ListNode* temp=head;
        while(temp->next!=slow){
            temp=temp->next;
        }
        temp->next=slow->next;
        delete slow;

return head;
    }


};