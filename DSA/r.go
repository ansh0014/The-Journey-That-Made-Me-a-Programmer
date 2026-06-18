// now i am doing the jump game v11
// i have to reach toe s.length-1 index 
// coditon i have to standing at index = i have give minjump and maxjum;
// docniton i+minjum<=j<=min(i+maxjum,s.length-1) s[j]='0
// this problem i have give the conditon ad reach and the destiny
// seems like the greedy approach is not working in this problem because we have to check all the possible jumps and we have to check if we can reach the end of the array or not
// we have to use the bfs approach to solve this problem because we have to check all the possible jumps and we have to check if we can reach the end of the array or not
// we have to use the queue to keep track of the jumps and the visited array to keep track of the visited elements
// but bfs is not optimal because of constraints
// we can optimize the bfs approach by using the two pointers approach to keep track of the jumps and the visited array to keep track of the visited elements
package DSA
func canReach(s string, minJump int, maxJump int) bool {	
	n:=len(s)
	queue:=make([]int,0)
	visited:=make([]bool,n)
	queue=append(queue,0)
	visited[0]=true
	farthest:=0
	for len(queue)>0{
		i:=queue[0]
		queue=queue[1:]
		start:=max(i+minJump,farthest+1)
		end:=min(i+maxJump,n-1)
		for j:=start;j<=end;j++{
			if s[j]=='0' && !visited[j]{
				if j==n-1{
					return true
				}
				queue=append(queue,j)
				visited[j]=true
			}
		}
		farthest=max(farthest,end)

	}
	return visited[n-1]
}
func max(a,b int)int{
	if a>b{
		return a
	}
	return b
}
func min(a,b int)int{
	if a<b{
		return a
	}

	return b
}