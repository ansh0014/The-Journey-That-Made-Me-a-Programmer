package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
)

func solve(nums []int, queries [][]int) []int {
    n := len(nums)

    prefix := make([]int, n+1)
    evenVals := []int{}

    for i := 0; i < n; i++ {
        prefix[i+1] = prefix[i]
        if nums[i]%2 == 0 {
            prefix[i+1]++
            evenVals = append(evenVals, nums[i])
        }
    }

    ans := []int{}

    for _, q := range queries {
        l, r, k := q[0], q[1], q[2]

        leftCnt := prefix[l]
        rightCnt := prefix[r+1]
        m := rightCnt - leftCnt

        // removed evens = evenVals[leftCnt:rightCnt]
        removed := evenVals[leftCnt:rightCnt]

        lo, hi := 2, 2*(k+m)

        for lo < hi {
            mid := (lo + hi) / 2
            if mid%2 == 1 {
                mid-- // keep even
            }

            // count removed evens <= mid
            cnt := sort.SearchInts(removed, mid+1)

            remaining := mid/2 - cnt

            if remaining >= k {
                hi = mid
            } else {
                lo = mid + 2
            }
        }

        ans = append(ans, lo)
    }

    return ans
}

func main() {
    reader := bufio.NewReader(os.Stdin)

    var n int
    fmt.Fscan(reader, &n)
    nums := make([]int, n)
    for i := range nums {
        fmt.Fscan(reader, &nums[i])
    }

    var q int
    fmt.Fscan(reader, &q)
    queries := make([][]int, q)
    for i := range queries {
        queries[i] = make([]int, 3)
        fmt.Fscan(reader, &queries[i][0], &queries[i][1], &queries[i][2])
    }

    ans := solve(nums, queries)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()
    for _, x := range ans {
        fmt.Fprintf(writer, "%d ", x)
    }
}