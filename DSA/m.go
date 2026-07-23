// now i am doing the Rearrange String to avoid character pair
// i have given a string s, and two distinc lowercase English letters x and y
// Rearrange the characters of s to construct a new string t such that
// t is permuatation of s
// every occurrence of y appear before every occurrence of x in t
// return any valid string t
// i understand i have return the permution of input in such that y appears before x in the output string
// approach is to count the number of x and y in the string and then create a new string with all y's followed by all x's and then append the rest of the characters in the original order
func rearrangeString(s string, x byte, y byte) string {
    countX := 0
    countY := 0

    others := make([]byte, 0)

    for i := 0; i < len(s); i++ {
        if s[i] == x {
            countX++
        } else if s[i] == y {
            countY++
        } else {
            others = append(others, s[i])
        }
    }

    result := make([]byte, 0, len(s))

    for i := 0; i < countY; i++ {
        result = append(result, y)
    }

    result = append(result, others...)

    for i := 0; i < countX; i++ {
        result = append(result, x)
    }

    return string(result)
}