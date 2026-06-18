// linear search with transposition
#include <iostream>
using namespace std;

int linearsearch(int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            if (i > 0)
            {
                swap(a[i], a[i - 1]);
            }
            return i;
        }
    }
    return -1;
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};

    int key;
    cout << "Enter an element: ";
    cin >> key;

    int pos = linearsearch(a, 5, key);

    if (pos != -1)
    {
        cout << "Found at index " << pos << endl;
    }
    else
        cout << "Not found" << endl;

    cout << "Array after search: ";
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
