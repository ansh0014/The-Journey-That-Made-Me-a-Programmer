// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n; 
//     cout << "Enter size of array: ";
//     cin >> n; 

//     int arr[n];
//     cout << "Enter " << n << " elements: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     // precompute 
//     int hash[13] = {0};
//     for (int i = 0; i < n; i++) {
//         hash[arr[i]] += 1;
//     }

//     cout << "\n--- Frequency Table ---\n";
//     for (int i = 0; i < 13; i++) {
//         if (hash[i] > 0) {
//             cout << "Number " << i << " appears " << hash[i] << " times.\n";
//         }
//     }

//     // fetch queries
//     int q;
//     cout << "\nHow many numbers do you want to check? ";
//     cin >> q;
    
//     cout << "Enter " << q << " numbers:\n";
//     while (q--) {
//         int number;
//         cin >> number;
//         cout << hash[number] << endl;
//     }

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    string s;
    cout<<"enter a string"<<endl;
    cin>>s;
    // first we precompute 
    int n=s.size(); 
    int hash[256]={0};    // 256 is for all possible string appear
    for (int i = 0; i < n; i++)
    {
         hash[s[i]] += 1;
    }
    
    // now we make the frequency tabel
  cout << "\n--- Frequency Table ---\n";
     for (int i = 0; i < 256; i++) {
         if (hash[i] > 0) {
             cout << "Number " << i << " appears " << hash[i] << " times.\n";
         }
     }


    // now we put the queries
    int q;
    cout<<"how many character do you want to check?"<<endl;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c]<<endl;
    }

    return 0;

}