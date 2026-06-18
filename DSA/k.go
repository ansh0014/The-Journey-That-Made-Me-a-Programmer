// now i am doing the longes common suffix queries
/*
i have two array of string words conatiner and wordsquer
for each wordquery[i] i need to find a string form wordsContainder that has the longes common suffin withe wordsWuer[i] . if i got tow or more steing in wordscontainer that the longes coommon suffinx i have find the smalles if therie same smalles what i got the same i have return 
// return the array of interfes ans ans[i] is the index stirng in wordscontainder that hte lognes common suffix with the wrordquery[i] if there is no string in wordscontainer that has common suffix with wordquery[i] then ans[i] = -1


*/
package DSA

func longestCommonSuffix(s1, s2 string) int {
	i, j := len(s1)-1, len(s2)-1
	count := 0
	for i >= 0 && j >= 0 && s1[i] == s2[j] {
		count++
		i--
		j--
	}
	return count
}
func stringIndices(wordsContainer []string, wordsQuery []string) []int {
	ans := make([]int, len(wordsQuery))
	smallestIndex := 0
	for i := 1; i < len(wordsContainer); i++ {
		if len(wordsContainer[i]) < len(wordsContainer[smallestIndex]) {
			smallestIndex = i
		}
	}
	for i, query := range wordsQuery {
		longestSuffix := -1
		index := smallestIndex
		for j, container := range wordsContainer {
			suffixLength := longestCommonSuffix(query, container)

			if suffixLength > longestSuffix {

				longestSuffix = suffixLength
				index = j

			} else if suffixLength == longestSuffix {

				if len(container) < len(wordsContainer[index]) {

					index = j

				} else if len(container) == len(wordsContainer[index]) {

					if j < index {
						index = j
					}
				}
			}
		}

		ans[i] = index
	}

	return ans
}