// now i am doing the weighted word mapping
// i understand thw problem weights of length where weight[i] represents the weight of ith lowercase English letter
// the weight of word is defined as sum of weights of character
// return string formed concatenating the words in the order of their weights from highest to lowest
// "abcd" is a word and weights are [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26]
// sum is 1+2+3+4 = 10
// 10%26=?
// ?mapped with the word and return the string formed by concatenating the words in the order of their weights from highest to lowest
func mapWordWeights(words []string, weights []int) string{
ans:=""
sum:=0
for _,word:=range words{
	sum=0
	for _,ch:=range word{
		sum+=weights[ch-'a']
	}
	mod:=sum%26
	ans+=string('z'-rune(mod))
	

}
return ans

}