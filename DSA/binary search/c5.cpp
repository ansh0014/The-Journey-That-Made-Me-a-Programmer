// now i am doing the search a 2d matrix
// i understand he question i have to take the index then i have set low and high then find the mid and then i have to check if the mid is equal to target then return true else if the mid is less than target then i will move the low pointer to mid+1 else i will move the high pointer to mid-1
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
bool searchMatrix(vector<vector<int>>&matrix,int target){
    int m=matrix.size();
    int n=matrix[0].size();
    int l=0;
    int h=m*n-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        int midValue=matrix[mid/n][mid%n];
        if(midValue==target) return true;
        else if(midValue<target) l=mid+1;
        else h=mid-1;
    }
    return false;
}
};