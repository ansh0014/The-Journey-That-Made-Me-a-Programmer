// now i am doing he jumb game v11
// this is greedy question
// condition is  i+minjum<=j<=min(i+maxjump,s.slent-1) and s[j]='0
// we have to eturn ture and false
// two loop used one for i and one for j
package main
import "fmt"
func canReach( s string, minJump int, maxJump int) bool {
	n:=len(s)
	i:=make([]bool,n)
	j:=0
	for i<n && j<n{
		s[i]='0'
		for j<=min(i+maxJump,n-1) && s[j]!='0' {
			j++
		}
		if j>min(i+maxJump,n-1) {
			return false
		}
	}
	return true

	
}
func min(a,b int)int {
	if a<b {
		return a
	}
}