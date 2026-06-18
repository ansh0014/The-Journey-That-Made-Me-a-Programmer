#include <iostream>
#include <vector>
using namespace std;

class Heap
{
public:
    vector<int> heap;

    void insert(int val)
    {

        heap.push_back(val);

        int i = heap.size();


        while (i > 1)
        {

            int parent = i / 2;

            if (heap[parent - 1] < heap[i - 1])
            {

                swap(heap[parent - 1], heap[i - 1]);

                i = parent;
            }
            else
            {
                break;
            }
        }
    }

  
    void heapify(int i, int n)
    {

        int left = 2 * i;
        int right = 2 * i + 1;

        int largest = i;

        if (left <= n && heap[left - 1] > heap[largest - 1])
        {
            largest = left;
        }

        if (right <= n && heap[right - 1] > heap[largest - 1])
        {
            largest = right;
        }

        if (largest != i)
        {

            swap(heap[i - 1], heap[largest - 1]);

            heapify(largest, n);
        }
    }

    void heapSort()
    {

        int n = heap.size();

        while (n > 1)
        {

            swap(heap[0], heap[n - 1]);

            n--;

            heapify(1, n);
        }
    }

    void print()
    {

        for (int i = 0; i < heap.size(); i++)
        {
            cout << heap[i] << " ";
        }

        cout << endl;
    }
};

int main()
{

    Heap h;

    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(15);
    h.insert(30);

    cout << "Max Heap:" << endl;
    h.print();

    h.heapSort();

    cout << "After Heap Sort:" << endl;
    h.print();

    return 0;
}