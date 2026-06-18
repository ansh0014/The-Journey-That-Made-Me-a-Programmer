// now we learn about the important topic which is map for the hashing
// now we learn about the unordered map
#include <bits/stdc++.h>
using namespace std;
// map<key , value >
// now we do hashing using the map
// map stored all the values in sorted form
// we can also use map for the character
// unorderd map is in non sorted form
int main()
{
    int n;
    cout << "enter a size of array" << endl;
    cin >> n;
    int arr[n];
    cout << "enter a array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // precompute
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]] += 1;
    }
    // iterate in the map
    for (auto it:mpp){
        cout<<it.first<<"->"<<it.second<<endl;
    }

    // now we make the quries for asking the no.
    int q;
    cout << "Quries" << endl;
    cin >> q;
    cout<<"asking which no. do you want to ask ? "<<endl;
    while (q--)
    {
        int number;
        cin >> number;
        // fetch
        
         cout << "Frequency of " << number << " is: " << mpp[number] << endl;
    }

    return 0;
}
