// now i am doing the valid digit number 
// input n=101 , x=0
// output true
// valit no. is it contains atleast one occurrence of x
// it doesn not start with the x
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
// bool valiDigit(int n, int x){
//     string s = to_string(n);
//     string t = to_string(x);
//     if(s[0] == t[0]) return false;
//     for(int i = 0; i < s.size(); i++){
//         if(s[i] == t[0]) return true;
//     }
//     return false;
// }};
// now i am doing the compare sums of bitonic part
// i have split array in two parts
// ascending part :from index to the peak element(inclusive)
// descending part: from the peak element to indx n-1(inclusive)
// return 0 if sum is ascending part 1 if sum is descending part and -1 if both are equal
// approach i used stack to store the elements of the array and then i have calculated the sum of the two parts and then i have compared the sums
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareBitonicSums(vector<int>& arr) {
        int n = arr.size();

        // 1. Find peak index
        int peak = 0;
        for(int i = 1; i < n; i++){
            if(arr[i] > arr[peak]){
                peak = i;
            }
        }

        // 2. Calculate sums
        int sumAsc = 0, sumDesc = 0;

        for(int i = 0; i <= peak; i++){
            sumAsc += arr[i];
        }

        for(int i = peak; i < n; i++){
            sumDesc += arr[i];
        }

        // 3. Compare
        if(sumAsc > sumDesc) return 0;
        else if(sumAsc < sumDesc) return 1;
        else return -1;
    }
};