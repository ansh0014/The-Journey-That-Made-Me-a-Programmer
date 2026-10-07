// now i am doing teh partition list
// given the head of linked list and value x, partition it such that all nodes less than x come before nodes greate than or equal to x
// we used two pointer technique to solve this problem
// one pointer is slow and the other is fast, we will move the fast pointer to find the node which is less than x and then we will move the slow pointer to find the node which is greater than or equal to x and then we will swap the values of these two nodes.
// even we used binary search technique to find the node which is less than x and then we will move the slow pointer to find the node which is greater than or equal to x and then we will swap the values of these two nodes.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
  if(head==NULL) return head;
//  first we will create two dummy nodes, one for the list of nodes less than x and the other for the list of nodes greater than or equal to x
        ListNode* lessHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);
        ListNode* less = lessHead;
        ListNode* greater = greaterHead;
        while(head!=NULL){
            if(head->val<x){
                less->next=head;
                less=less->next;
            }
            else{
                greater->next=head;
                greater=greater->next;
            }
            head=head->next;
        }
        greater->next=NULL;
        less->next=greaterHead->next;
        return lessHead->next;
    }
};