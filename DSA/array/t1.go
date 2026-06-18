// now i am doing the find the length of the longest common prefix
// first i want to understand the the question
// i understand the question i have to find the prefix of two array possible prefix then compare the prefix of two array if prexi is their in the other array then i have return the longest common prefix if not i have to return 0
// approach i have to used the prefix sum and then i will compare the prefix of two array if prexi is their in the other array then i have return the longest common prefix if not i have to return 0
package main

import (
	"fmt"
	"strconv"
)
func digits(num int) int{
	count:=0
	for num>0{
		count++
		num=num/10
	}
	return count
}
func longestCommonPrefix (arr1 [] int , arr2 []int)int{
prefix:=make(map[int]bool)
ans:=0
for _, num:=range arr1 {
for num>0{
	prefix[num]=true
	num/=10
}

}
for _, num:=range arr2 {
	for num>0{
		if prefix[num] {
			length:=digits(num)
			if length>ans{
				ans=length
			}
			
		}
		num/=10
	}
	return ans
}
}
