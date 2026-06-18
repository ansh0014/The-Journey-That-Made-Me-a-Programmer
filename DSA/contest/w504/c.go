func findLexMaxMEXArray(nums []int) []int {
    result := []int{}
    start := 0
    n := len(nums)

    for start < n {
        rem := nums[start:]

        firstOcc := make(map[int]int)
   for i, v := range r {
    _, exists := firstOcc[v]
    if !exists {
        firstOcc[v] = i
    }
}
        }

        maxIdx := -1
        mex := 0
        for {
            idx, ok := firstOcc[mex]
            if !ok {
                break
            }
            if idx > maxIdx {
                maxIdx = idx
            }
            mex++
        }

        bestK := maxIdx + 1
        if bestK < 1 {
            bestK = 1
        }

        result = append(result, mex)
        start += bestK
    }

    return result
}