// now i am doing the maximum total subarray value 1

// nums[1,3,2] , k=2 output is 4 
// let dive in question i have given integer array nums of lenght n and integer k
// i need to choose k non empty subarray nums[l..r] of nums subrrays my overlap and exact same subarray (same l and r) cna be choosen more than once
// teh value of subarray nums[l..r] is defined as max(nums[l..r]) -min(nums[l..r])
// return the maximum total value
func maxTotalValue(nums []int , k int) int64{
maxVal:=nums[0]
minVal:=nums[0]
for i:=0;i<len(nums);i++{
	if nums[i]>maxVal{
		maxVal=nums[i]
	}
	if nums[i]<minVal{
		minVal=nums[i]
	}
}
return int64(maxVal-minVal)*int64(k)

}