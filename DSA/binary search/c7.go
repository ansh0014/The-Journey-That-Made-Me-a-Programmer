// now i am doing the unique search trees 11
// given an integer n, return all the structurally unique BST which has exactly n nodes of unique values from 1 to n. Return the anser in any order.
// approach we can used recurrsive solution to solve this problem. we can use the concept of recursion to generate all possible unique BSTs for a given number of nodes. The idea is to select each number from 1 to n as the root and recursively generate all possible left and right subtrees for that root.
// we can use a helper function to generate the trees for a given range of values. The base case is when the start value is greater than the end value, in which case we return a list containing None (representing an empty tree). For each number in the range, we recursively generate all possible left and right subtrees and combine them to form unique BSTs.
// package main
// import(
// 	"fmt"
// )
// type TreeNode struct{
// 	val int
// 	left *TreeNode
// 	right *TreeNode
// }
// func solve(start int, end int) []*TreeNode{
// 	res:= []*TreeNode{}

// 	if(start>end){
// 		res=append(res, nil)
// 		return res
// 	}
// 	// now we implement the recursion to generate the trees for a given range of values. The base case is when the start value is greater than the end value, in which case we return a list containing None (representing an empty tree). For each number in the range, we recursively generate all possible left and right subtrees and combine them to form unique BSTs.
// 	for i:=start; i<=end; i++{
// 		left:=solve(start, i-1)
// 		right:=solve(i+1, end)
	
// 		for _, l := range left {
// 			for _, r := range right {
// 				root := &TreeNode{val: i, left: l, right: r}
// 				res = append(res, root)
// 			}
// 		}

// 	}
// 	return res


// }
// func generateTrees(n int) []*TreeNode {
// if n==0{
// 	return []*TreeNode{}
// }
// return solve(1, n)
// }


