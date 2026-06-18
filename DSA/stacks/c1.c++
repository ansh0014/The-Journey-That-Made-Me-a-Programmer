#include <iostream>
using namespace std;
struct stack
{
    int size;
    int top;
    int *s;
};
void create(struct stack *k)
{
    cout << "Enter size:";
    cin >> k->size; 
    k->top = -1;    
    k->s = new int[k->size];
}
void Display(struct stack k)
{
    int i;
    for (i = k.top; i >= 0; i--)
    {
        cout << k.s[i] << endl;
    }
}
void push(struct stack *k, int x)
{
    if (k->top == k->size - 1)
    {
        cout << "Stack overflow";
    }
    else
    {
        k->top++;
        k->s[k->top] = x;
    }
}
int pop(stack *k)
{
    int x = -1;
    if (k->top == -1)
    {
        cout << "Stack underflow" << endl;
    }
    else
    {
        x = k->s[k->top];
        k->top--;
    }
    return x;
}
int peek(stack k, int pos)
{
    int x = -1;
    if (k.top - pos + 1 < 0)
    {
        cout << "eroor" << endl;
    }
    else
    {
        x = k.s[k.top - pos + 1];
    }
    return x;
}

int main()
{
    struct stack st;
    int choice, x, pos;

    create(&st);

    do
    {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element to push: ";
            cin >> x;
            push(&st, x);
            break;

        case 2:
            x = pop(&st);
            if (x != -1)
                cout << "Popped element: " << x << endl;
            break;

        case 3:
            cout << "Enter position to peek: ";
            cin >> pos;
            x = peek(st, pos);
            if (x != -1)
                cout << "Element at position " << pos << " is: " << x << endl;
            break;

        case 4:
            Display(st);
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
