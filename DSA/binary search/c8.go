// now i am doing the sprial matrix 1v
// i have given two integers m and n, which represent the dimensions of a matrix
// i have also given the head of liked of integers
// generate the m*n marix that conatins the integers in the linked list preseted in sprial order(clockwise) starting form the top-left of the matreix if there are remaining empty spaces fill them with -1.
// approach i can make the grid then fill the grid using switch case and then return the grid
package main
import "fmt" 
type ListNode struct {
      Val int
      Next *ListNode
  }

  func spiralMatrix(m int, n int, head *ListNode) [][]int {
grid := make([][]int, m)

for i:=range m{
	grid[i] = make([]int, n)
	for j:=range n{
		grid[i][j] = -1
	}

}
top:=0
bottom:=m-1
right:=n-1
left:=0
for head!=nil && top<=bottom && left<=right{
	for j:=left;j<=right&&head!=nil;j++{
		grid[top][j] = head.Val
		head = head.Next
	}
	top++
	for i:=top;i<=bottom&&head!=nil;i++{
		grid[i][right] = head.Val
		head = head.Next
	}
	right--
	for j:=right;j>=left&&head!=nil;j--{
		grid[bottom][j] = head.Val
		head = head.Next
	}
	bottom--
	for i:=bottom;i>=top&&head!=nil;i--{
		grid[i][left] = head.Val
		head = head.Next
	}
	left++
}
return grid
}



