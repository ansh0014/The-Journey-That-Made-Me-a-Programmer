#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        
        vector<int> vals;
        for(int i = 0; i < n; i++){
            vals.push_back(a[i]);
            vals.push_back(b[i]);
        }
        
        sort(vals.begin(), vals.end());
        cout << vals[n-1] << "\n";
    }
}