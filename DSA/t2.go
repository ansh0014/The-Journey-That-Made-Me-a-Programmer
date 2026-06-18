// now i am doing the cinema seat allocation
// first i have to understand the problem statement
// i understand the problem statemenet input is the reserved seat which they given the row and column
// i have to return the mximum number of four person families can be seated in the cinema hall
// how  n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
// output=4 , ans is that the output is four because in the first row we can seat one family in the middle and one family in the right side and in the second row we can seat one family in the left side and in the third row we can seat one family in the middle and one family in the right side
// means int the first 1,4 and 1,5 and 1,6 and 1,7 we can seat one family and in the first row we can seat one family in the right side means 1,9 and 1,10 and in the second row we can seat one family in the left side means 2,2 and 2,3 and 2,4 and 2,5 and in the third row we can seat one family in the middle means 3,4 and 3,5 and 3,6 and 3,7 and in the third row we can seat one family in the right side means 3,8 and 3,9 and 3,10
// maximum is 4
// approach is that we can create a map to store the reserved seats and then we can check for each row if we can seat a family in the left side or in the middle or in the right side and we can count the number of families we can seat in each row and then we can return the total count of families we can seat in the cinema hall
// func maxNumberOfFamilies(n int, reservedSeats [][]int) int {
//     reserved := make(map[int]map[int]bool)

//     for _, seat := range reservedSeats {
//         row, col := seat[0], seat[1]
//         if reserved[row] == nil {
//             reserved[row] = make(map[int]bool)
//         }
//         reserved[row][col] = true
//     }

//     total := (n - len(reserved)) * 2

//     checkFamily := func(row int) int {
//         left := !reserved[row][2] && !reserved[row][3] && !reserved[row][4] && !reserved[row][5]
//         right := !reserved[row][6] && !reserved[row][7] && !reserved[row][8] && !reserved[row][9]
//         middle := !reserved[row][4] && !reserved[row][5] && !reserved[row][6] && !reserved[row][7]

//         if left && right {
//             return 2
//         }
//         if left || right || middle {
//             return 1
//         }
//         return 0
//     }

//     for row := range reserved {
//         total += checkFamily(row)
//     }

//     return total
// }
// now i am doing the furthest point form origin
// i have to understand the problem statement means that move[i]='l' or move[i]='_ means move left , move[i]='r' moves[i]='_ right
// input is "l_rl__r" the output is 3 The furthest point we can reach from the origin 0 is point -3 through the following sequence of moves "LLRLLLR".
// i understand the problem i have to take the 0 index if i got l first i move to -1 then i have _ which means the left move to -2 then i got r move to -1 then l move to -2 then __ move to -4 then i got r move to -3 i have return only int 3
// approach is that we can iterate through the moves and keep track of the current position and update the maximum distance from the origin
// func furthestDistanceFromOrigin(moves string) int {
// 	l := 0
// 	r := 0
// 	b := 0
// 	for _, move := range moves {
// 		if move == 'l'|| move=='L' {
// 			l++
// 		} else if move == 'r' || move == 'R' {
// 			r++
// 		} else {
// 			b++
// 		}
// 	}
// 	maxDist := abs(l-r) + b

// 	return maxDist
// }
// func abs(x int) int {

// 	if x < 0 {
// 		return -x
// 	}
// 	return x
// }
// now i am doing the detect cycles in 2d grid
// i understand the question statement i have given the grid of m*n then i have to move in the grid adjacent cells and i have to check if there is a cycle in the grid or not
// i go up down left right and i have to check if there is a cycle in the grid or not
// input is [["a","b","c"],["d","e","f"],["g","h","i"]]
// output is false because there is no cycle in the grid

// one approach using the loop is that i can iterate check the conditon of the adjacent cells and if i found the same character then i can check if there is a cycle or not
func containCycle(grid [][]byte) bool  {
	m:=len(grid)
	n:=len(grid[0])
	visited:=make([][]bool,m)
	for i:=0;i<m;i++{
		visited[i]=make([]bool,n)
	}
	for i:=0;i<m;i++{
		for j:=0;j<n;j++{
			if !visited[i][j]{
				if dfs(grid, visited, i, j, -1, -1) {
					return true
				}
			}
		}
	}
	return false
}
