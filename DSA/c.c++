// now i am doing the minimum elements after replacement with digit sum
// i have to replace the element with the sum of digits
// minimum element after replacement with digit sum is the minimum element in the array after replacing each element with the sum of its digits until we get a single digit
// i think i have to use the recursive function to get the sum of digits until we get a single digit
// problem is that [999,19 199] the minimum is 10 because 1+9+9=19
#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
// i have to make the summ of all element 
int sumOfDigits(int n){
	int sum=0;
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	return sum;
}
int minimumElement(vector<int>& nums){
	int n=nums.size();
	for(int i=0;i<nums.size();i++){
		nums[i]=sumOfDigits(nums[i]);
	}
	int min=nums[0];
	for(int i=1;i<nums.size();i++){
		if(nums[i]<min){
			min=nums[i];
		}
	}
	return min;
}
};

	
