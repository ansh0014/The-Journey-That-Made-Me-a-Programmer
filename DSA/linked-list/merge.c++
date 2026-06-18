#include <iostream>
using namespace std;
struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int x) : data(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *mergetwolists(ListNode *L1, ListNode *L2)
    {
        if(L1==NULL){
            return L2;
        }
        if (L2==NULL)
        {
    return L1;
        }
        
        if (L1->data < L2->data)
        {
            L1->next = mergetwolists(L1->next, L2);
            return L1;
        }
        else
        {
            L2->next = mergetwolists(L1, L2->next);
            return L2;
        }
    }
};