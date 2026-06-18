// now we started with the array in good manner
// first we write the  basic program or to insert the element in the given array
// we use vector for that 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Create a vector
    vector<int> v = {1, 2, 3};

    // 1. push_back -> add element at end
    v.push_back(5); // v = {1,2,3,5}

    // 2. pop_back -> remove last element
    v.pop_back(); // v = {1,2,3}

    // 3. insert -> insert at any position
    v.insert(v.begin() + 2, 10); // v = {1,2,10,3}

    // 4. erase -> remove element at index
    v.erase(v.begin() + 2); // v = {1,10,3}

    // 5. size -> number of elements
    cout << "Size: " << v.size() << endl;

    // 6. front and back
    cout << "Front: " << v.front() << endl; // first element
    cout << "Back: " << v.back() << endl;   // last element

    // 7. at -> access safely
    cout << "Element at index 1: " << v.at(1) << endl;

    // 8. clear -> remove all elements
    v.clear();
    cout << "After clear, size: " << v.size() << endl;

    // 9. empty -> check if vector is empty
    if (v.empty()) cout << "Vector is empty" << endl;

    return 0;
}
