// Process string with specail operations 1
// i have to build new string result by processing s according to the following rules from left to right
// 1) if the letter is lowercase English letter append it to result
// A "*" removes the last character from result, if it exists
// A "#" duplicates the current result and appends it to itself
// A '%' reverses the current result
// return the final string result after processing all characters in s
// we used hashing for storing and strack using stack for processing the string
func processStr(s string) string{
	stack := []string{}

	for _, ch := range s {
	switch {
		case ch >= 'a' && ch <= 'z':
			stack = append(stack, string(ch))
		case ch == '*':
			if len(stack) > 0 {
				stack = stack[:len(stack)-1]
			}
		case ch == '#':
			if len(stack) > 0 {
				stack = append(stack, stack...)
			}
		case ch == '%':
			for i, j := 0, len(stack)-1; i < j; i, j = i+1, j-1 {
				stack[i], stack[j] = stack[j], stack[i]
			}
	}

}
return strings.Join(stack, "")
}