// now i am doing hte score of Parentheses
// i used stack and track the pratentheses and when i found the closing parenthesis then i will pop the stack and calculate the score of the parentheses
// () ->1 AB A+B A and B balanced (A) 2*A 
package main

import "fmt"

func scoreOfParentheses(s string) int {
	stack:=[]int{0}
	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			stack = append(stack, 0)
		} else {
	
			v := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			if v == 0 {
	
				stack[len(stack)-1] += 1
			} else {
		
				stack[len(stack)-1] += 2 * v
			}
		}
	}
	return stack[0]
}

func main() {
	fmt.Println(scoreOfParentheses("(()())"))
}
	
