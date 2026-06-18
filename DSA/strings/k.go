// now i am doing the lexicographically maximum MEX array
// i have to construct an array of result by repeatedly perfomring the fllow oper
// i have chhose an integer k such that 1<=k<=len(nums)
// compute the MEX of the first k elements of nums
// append the MEX to the result array
// remove the first k elemts form nums
// return the lexicorgraphically maximum array result
// the MEX of an array is the smallest non-negative integer not present in the array
// example nums=[0,1,0] output [2,1]
// i want the large possible MEX for current because of lixicographical order
// i have to use greedy approach to get the maximum MEX at each step
func maximumMEX(nums []int) []int {
	result := []int{}

	for len(nums) > 0 {

		freq := make(map[int]int)
		for _, x := range nums {
			freq[x]++
		}

		mex := 0
		for {
			if freq[mex] == 0 {
				break
			}
			mex++
		}

		result = append(result, mex)

		if mex == 0 {
			nums = nums[1:]
			continue
		}

		seen := make(map[int]bool)
		k := 0

		for i := 0; i < len(nums); i++ {

			if nums[i] < mex && !seen[nums[i]] {
				seen[nums[i]] = true
			}

			if len(seen) == mex {
				k = i + 1
				break
			}
		}

		nums = nums[k:]
	}

	return result
}