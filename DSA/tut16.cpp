#include<iostream>
using namespace std;

int BinarySearch(int a[], int l, int h, int key) {
    if (l <= h) {
        int mid = (l + h) / 2;
        if (a[mid] == key) {
            return mid;
        }
        else if (key < a[mid]) {
            return BinarySearch(a, l, mid - 1, key);
        }
        else {
            return BinarySearch(a, mid + 1, h, key);
        }
    }
    return -1; // not found
}

int main() {
    int a[5] = {10, 11, 12, 13, 14};
    int key = 9;

    int res = BinarySearch(a, 0, 4, key);

    if (res != -1)
        cout << "Element found at index " << res << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
