#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
void f(int ind, vector<int>& ds, int arr[], int n) {
    if(ind >= n) {
        for(auto it : ds) {
            cout << it << " ";
        }
        cout << endl;
        return;
    }

// Take or pick the particular index into the subsequence

    ds.push_back(arr[ind]);
    f(ind+1, ds, arr, n);


    ds.pop_back();
// not pick , or not take condition, this element is ntoa dded to you subesequence

    f(ind+1, ds, arr, n);
}
int main(){
    int arr[]={3,1,2};
    int n=3;
    vector<int>ds;
    f(0,ds,arr,n);
    return 0;
}