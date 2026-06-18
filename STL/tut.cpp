// #include <bits/stdc++.h>
// using namespace std;
// // first we learn about the pair
// // pair is defined in such manner pair in terms of two three etc'
// void explain()
// {

//     // pair<int, int> p = {1, 3};
//     // this is way how we print the pair the pair fist means first no.
//     // cout << p.first << " " << p.second;
//     // for the three we used the nested property meand pair inside the pair
// cout<<endl;
//     // pair< int, pair<int, int>>p ={10,{20,30}};

//     // cout<<p.first<<" "<< p.second.second<<" "<<p.second.first<<" ";

//     // Output: 10 30 20
//     // Here's the breakdown:
//     // p.first → 10
//     // p.second.second → 30 (inner pair's second)
//     // p.second.first → 20 (inner pair's first)
//     pair<int,int> arr[]={{1,2},{3,4},{5,6}};
//     cout<<arr[1].first;
// }

// int main()
// {
//     explain();
// }
// now we learn vector
#include <bits/stdc++.h>
using namespace std;
void explain()
{
    // a vector is dnamic array provided by the c++ STL
    // You don’t need to declare size in advance.

    // It can grow or shrink automatically during runtime.

    // Very useful in competitive programming and DSA.
    // vector<int> v; // v= any name means a ansul anythings

    // v.push_back(1);  //  their empty container so we have to add the value using the push back
    //                  // this means v=[1]
    // v.push_back(10); // v = [5, 10]
    // v.push_back(15); // v = [5, 10, 15]
    // v.emplace_back(20);
    //     | Feature          | `push_back()`                    | `emplace_back()`                               |
    // | ---------------- | -------------------------------- | ---------------------------------------------- |
    // | Purpose          | Adds an element to the end       | Constructs an element in-place                 |
    // | Speed            | Slightly slower (may copy/move)  | Slightly faster (no copy, constructs directly) |
    // | Use with objects | Needs a fully constructed object | Directly passes constructor arguments          |
    // vector<pair<int, int>> v;
    // v.push_back({1, 2});
    // v.emplace_back(1, 2);
    // push_back and emplace_back have not similar syntax
    // vector<int> v(3,100);
    // vector<int> v(3, 100);  // ✅ This means: 3 elements, each = 100
    // means size of array is 3 and all the elemnst is 100
    // vector<int>v{5};
    vector<int> v1{4, 1, 2, 3, 59};
    // vector<int>v2{v1};   // this how we copy the container into another container
    // to print the vecotr we print like the array
    // cout<<v1[3];
    // thier is anoter way to print the vector
    // as we know in array memmory is addressed
    // vector<int>::iterator c = v1.begin();
    // cout << *(c) << endl;

    // c++;
    // cout << *(c) << " ";
    // now we learn how to print the entire vector
    // for (vector< int>::iterator c=v1.begin(); c!=v1.end();c++)
    // {
    //     cout<<*(c)<<endl;
    // }
    // This is long way to print the vector
    // now we learn about the shortcut
    // for (auto  c: v1)
    // {
    //     cout<<c<<endl;
    // }
    // now we lern how erase in vector
    v1.erase(v1.begin() + 1); // this fuction delete the vector
    // this is way we delete the single max_element
    // now we learn how to delete the multiple element from the vector
    v1.erase(v1.begin() + 1, v1.begin() + 3); // this is way to delete the multiple elemnt
    // now we learn how to insert the elment

    // for ( auto c:v1)
    // {
    //     cout<<(c)<<endl;
    // }
    vector<int> v2{1,2,3,4,};  
    // v2.insert(v2.begin(), 7);     // this is way we inster a element in the vecotro
    // now we learn how to inster more elemnt in the vector
    // v2.insert(v2.begin()+1,8);

    for (auto c : v2)
    {
        cout << (c) << endl;
    }
}
int main()
{
    explain();
}
