// now i am doing the construct uniform parity array 11
// i have given to construct another array nums2 of length n such that elements in nums2 are either all odd or all even
// for each index i, nums2[i]=nums1[i].
// nums2[i]=nums1[i]-nums1[j], for an index j!=i such that nums[i]-nums1[j]>=1
// return true if it is possible to construct such an array , ohterwise return false
// this is question of parity 
// so we can check the parity of the array if all elements are even or all elements are odd then we can construct the array otherwise we can't

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
      bool uniformArray(vector<int>& nums1) {
          int minodd=INT_MAX;
          int mineven=INT_MAX;
          for(int x:nums1){
            if(x%2==0){
              mineven=min(mineven,x);
            }else{
              minodd=min(minodd,x);
            }
      
       
          
        }
          if (minodd==INT_MAX || mineven==INT_MAX){
              return true;
          }
          return minodd< mineven;
        }};
      