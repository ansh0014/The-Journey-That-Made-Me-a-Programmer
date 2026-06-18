// now i am doing the bulb switcher problem
// this is greedy problem
package main
import "fmt"
func bulbSwitch(n int) int{
	count:=0
	for i:=1;i*i<=n;i++{
		count++
	}
	return count
}