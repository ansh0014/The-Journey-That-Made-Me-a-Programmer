package array

import (
	"fmt"
	"sort"
)

// now i am doing the minimum size subrray sum
// func minSubArrayLen(target int, nums []int) int {
// 	// we used the prefix sum to find the sum of the subarray in O(1) time
// 	n:=len(nums)
// 	left:=0
// 	sum:=0
// 	ans:=n+1
// 	for right:=0;right<n;right++ {
// 		sum+=nums[right]
// 		for sum>=target {
// 			ans=min(ans,right-left+1)
// 			sum-=nums[left]
// 			left++
// 		}
// 	}
// 	if ans==n+1{
// 		return 0
// 	}
// 	return ans

// }
// func min(a,b int)int {
// 	if a<b {
// 		return a
// 	}
// 	return b
// }
// now i am doing hte minimum common value
// use the if else condition and first i have sort the array and then i will use the two pointer approach to find the minimum common value
func getCommon(nums1 []int , nums2 []int ) int{
	sort .Ints(nums2)
	sort .Ints(nums1)
	i:=0
	j:=0
	for i<len(nums1)&& j<len(nums2) {
		if nums1[i]==nums2[j] {
			return nums1[i]
		}
		if nums1[i]<nums2[j] {
			i++
		}else {
			j++
		}
	}
	return -1

}