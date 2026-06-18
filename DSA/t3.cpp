// now i am doing the furthest houses with different colors
// no. of index show the color i have to return the maximum distance 
// apporach i used linear search for that i have to check the first and last index of that color and then i have to check the distance between them and then return the maximum distance
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:
//     int maxDistance(vector<int>& colors){
//         int n=colors.size();
//         int maxdist=0;
//         for(int i=0;i<n;i++){
//             for(int j=n-1;j>i;j--){
//                 if(colors[i]!=colors[j]){
//                     maxdist=max(maxdist,j-i);
//                     break;
//                 }
//             }

//         }
//         return maxdist;
//     }
// };
// now i am doing the maximum distance between the a pair of values
// apporach i have to two loop with nums1[i]<=nums2[j] i have create the pair data structure and then i have to check the distance between them and then return the maximum distance
// with the above approach is O(n^2) time complexity so we can optimize it by using the two pointer approach

#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int maxDistance(vector<int>& nums1, vector<int>& nums2){
    int maxdist=0;
    int n1=nums1.size();
    int n2=nums2.size();
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(nums1[i]<=nums2[j]){
            maxdist=max(maxdist,j-i);
            j++;
        }
        else{
            i++;
        }
    }
    return maxdist;
}
};