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
    ListNode *Search(ListNode *head, int key)
    {
        ListNode *p = head;
        ListNode *q = NULL;

        while (p != NULL)
        {
            if (p->data == key)
            {
                if (q == NULL)
                    return head;

                q->next = p->next;
                p->next = head;
                head = p;
                return head;
            }
            q = p;
            p = p->next;
        }
        return head;
    }
};

ListNode *Insertion(ListNode *head, int data)
{
    int pos;
    cout << "Enter position: ";
    cin >> pos;

    ListNode *t = new ListNode(data);

    if (pos == 0)
    {
        t->next = head;
        return t;
    }

    ListNode *p = head;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }

    t->next = p->next;
    p->next = t;

    return head;
}
ListNode *InsertSort(ListNode *head, int data)
{
    ListNode *p = head;
    ListNode *q = NULL;
    ListNode *t = new ListNode(data);
    if (head == NULL)
    {
        return t;
    }
    if (data < head->data)
    {
        t->next = head;
        return t;
    }

    while (p != NULL && p->data < data)
    {
        q = p;
        p = p->next;
    }
    q->next = t;
    t->next = p;
    return head;
};
ListNode *DeleteNode(ListNode *head, int pos)
{
    ListNode *q = NULL;
    ListNode *p = head;
    if (pos == 0)
    {
        head = head->next;
        delete p;
        return head;
    }
    else
    {
        for (int i = 0; i < pos && pos - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    Solution obj;
    head = obj.Search(head, key);

    int data;
    cout << "Enter data to insert: ";
    cin >> data;

    head = Insertion(head, data);

    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
