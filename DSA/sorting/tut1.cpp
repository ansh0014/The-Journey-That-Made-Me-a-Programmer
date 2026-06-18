// // we are learning the quick sort
// #include <bits/stdc++.h>
// using namespace std;

// int partation(vector<int>& arr, int low , int high) {
//     int pivot = arr[low];
//     int i = low;
//     int j = high;

//     while (i < j) {
//         while (arr[i] <= pivot && i <= high - 1) {
//             i++;
//         }
//         while (arr[j] >= pivot && j >= low + 1) {
//             j--;
//         }
//         if (i < j) swap(arr[i], arr[j]);
//     }
//     swap(arr[low], arr[j]);
//     return j;
// }

// void qs(vector<int>& arr, int low , int high) {
//     if (low < high) {
//         int pID = partation(arr, low , high);
//         qs(arr, low , pID - 1);
//         qs(arr, pID + 1 , high);
//     }
// }

// vector<int> quicksort(vector<int> arr) {
//     qs(arr, 0, arr.size() - 1);
//     return arr;
// }

// int main() {
//     vector<int> arr = {10, 7, 8, 9, 1, 5};

//     cout << "Original array: ";
//     for (int i = 0; i < arr.size(); i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     vector<int> sorted = quicksort(arr);

//     cout << "Sorted array: ";
//     for (int i = 0; i < sorted.size(); i++) {
//         cout << sorted[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }
// *********** Now we learn about the selection sort**********
#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        swap(arr[mini], arr[i]);
    }
}

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

int main()
{
    int n;
    cout<<"enter a value of n"<<endl;
    cin >> n;
    cout<<"enter a array"<<endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // selection_sort(arr, n);
    insertion_sort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
