#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void Insert(ListNode *head, int pos, int x)
    {

        ListNode *t = new ListNode(x);
       
        if (pos == 0)
        {

            if (head == NULL)
            {
                t->next = t;
                head = t;
                return;
            }

            ListNode *p = head;
            while (p->next != head)
                p = p->next;

            p->next = t;
            t->next = head;
            head = t;
            return;
        }

        ListNode *p = head;
        for (int i = 0; i < pos - 1; i++)
            p = p->next;

        t->next = p->next;
        p->next = t;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *fourth = new ListNode(4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    fourth->next = head;

    Solution obj;

    obj.Insert(head, 0, 99);

    obj.Insert(head, 3, 50);

    ListNode *temp = head;
    do
    {
        cout << temp->val << " ";
        temp = temp->next;
    } while (temp != head);

    return 0;
}
