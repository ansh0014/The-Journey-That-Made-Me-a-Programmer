// right now the i am doing the convert sorted array to binary search tree
// approach i have to find the mid of the array and then i have to make the mis as root and descending the left part of the array to left subtree and descending the right part of the array to right subtree

// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
// TreeNode* sortedArrayToBST(vector<int>& nums){
//     if(nums.empty()) return NULL;
//     int mid=nums.size()/2;
//     TreeNode* root=new TreeNode(nums[mid]);
//     vector<int> leftSub(nums.begin(),nums.begin()+mid);
//     vector<int> rightSub(nums.begin()+mid+1,nums.end());
//     root->left=sortedArrayToBST(leftSub);
//     root->right=sortedArrayToBST(rightSub);
//     return root;
// }
// };
// now i am doing the words withing twos edits of dictionary
// i understand the question i have given the quieres and disctiorny i have to match the queries with the dictionary for that i have to change the character only two times
// approach i used loop auto for traverasl the both the queries and the dictionary and then i have to check if the character is same then i will move to next character else i will change the character and then i will check if the number of changes is less than or equal to 2 then i will push the query in the answer vector
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
// vector<string> twoEditsWords(vector<string>& queries,vector<string>& dictionary){
//     int n1=queries.size();
//     int n2=dictionary.size();
//     vector<string> ans;
//     for(auto &querie:queries){
//         for(auto &dict:dictionary){
//             int changes=0;
//             for(int i=0;i<querie.size();i++){
//                 if(querie[i]!=dict[i]) changes++;
//             }
//             if(changes<=2){
//                 ans.push_back(querie);
//                 break;
//             }
        
      
//     }
//     return ans;
// }
// }};
// now i am doing the minimum pair removal to sort array 1
// i understand the question i have the select the adjacent pair and find the minimum sum 
// i have to used pair ds for that and i have to geration subarray but i have to choose adjacent pair only i have to use left and right pointer for that and then i have to find the minimum sum and then i have to remove the pair and then i have to count the number of operations and then return the operations
// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
//     public:

//    bool isSorted(vector<int>& nums){
//     int n=nums.size();
//     for(int i=1;i<n;i++){
//         if(nums[i]<nums[i-1]) return false;
//     }
//     return true;
//    }

//    int minimumPairRemoval(vector<int> &nums){
//     int n=nums.size();
//     int op=0;
//     while(!isSorted(nums)){
//         int minSum=INT_MAX;
//         int idx=0;
//         for(int i=0;i<nums.size()-1;i++){
//             if(nums[i]+nums[i+1]<minSum){
//                 minSum=nums[i]+nums[i+1];
//                 idx=i;
//             }
//         }
//         nums[idx] = nums[idx] + nums[idx+1];
//             nums.erase(nums.begin() + idx + 1);
//         op++;
//     }

//    return op;
// }
// };

// now i am doing the maximum product of subarray
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int maxProduct(vector<int>&nums){
    int n=nums.size();
    long long maxProd=INT_MIN;
    long long minProd=INT_MAX;
    long long ans=INT_MIN;
for(int i=0;i<n;i++){
    if(nums[i]<0){
        swap(maxProd,minProd);
    }
    maxProd=max( (long long) nums[i],maxProd*nums[i]);
    minProd=min( (long long) nums[i],minProd*nums[i]);
    ans=max(ans,maxProd);
}
return ans;
}
};