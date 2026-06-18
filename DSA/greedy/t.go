// now i am doing the jump game 111
// this is greedy approach
// i will checks the 0 element where the 0 i have to reach and then i will check the left and right side of the 0 element and if i can reach the 0 element then i will return true otherwise false
// the time complexity of this approach is O(n) and space complexity is O(1)
// i can jum i+arr[i] and i-arr[i] and i can jump to the left and right side of the 0 element
// recurssion is not a good approach for this problem because it will take a lot of time and space complexity will be O(n) because of the recursive stack
// the best approach for this problem is to use a queue and a visited array to keep track of the visited elements and then we can use a while loop to check the left and right side of the 0 element and if we can reach the 0 element then we will return true otherwise false

package main

import "fmt"

// func canReach(arr []int , start int)bool  {
// n:=len(arr)
// visited:=make([]int,n)
// queue:=make([]int,0)
// queue=append(queue,start)
// for len(queue)>0 {
// 	curr:=queue[0]
// 	queue=queue[1:]
// 	if arr[curr]==0{
// 		return true
// 	}
// 	visited[curr]=1
// 	left:=curr-arr[curr]
// 	right:=curr+arr[curr]
// 	if left>=0 && visited[left]==0{
// 		queue=append(queue,left)
// 	}
// 	if right<n && visited[right]==0{
// 		queue=append(queue,right)
// 	}

// }
// return false

// }
// now we are doing the maximum number of jumps to reach the end of the array
// this is greedy approach
// i have to understand the problem first and then i will try to solve it
// the problem is to find the maximum number of jumps to reach the end of the array
// what is target is the end of the array and what is the jump is the value of the element in the array
// i used the queue to keep track of the jumps and the visited array to keep track of the visited elements
func maximumJumps(nums []int, target int) int {
	n := len(nums)
	var dfs func(int) int
	dfs = func(i int) int {
		if i == n-1 {
			return 0
		}
		maxJumps := -1
		for j := i + 1; j < n; j++ {
			if abs(nums[i]-nums[j]) <= target {
				jumps := dfs(j)
				if jumps != -1 {
					maxJumps = max(maxJumps, jumps+1)
				}
			}
		}
		return maxJumps
	}
	return dfs(0)
}
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
