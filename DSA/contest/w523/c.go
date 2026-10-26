package main


import (
    "strconv"
    "sync"
)

type BusBooking struct {
    mu          sync.Mutex
    seats       [][4]int
    totalTime   int
    bookedCount int
}

func Constructor(n int) BusBooking {
    return BusBooking{
        seats: make([][4]int, n),
    }
}

func (this *BusBooking) Toggle(seat string) {
    this.mu.Lock()
    defer this.mu.Unlock()

    col := int(seat[0] - 'A')
    row, _ := strconv.Atoi(seat[1:])
    row--

    current := this.seats[row][col]

    if current != 0 {
        this.totalTime -= current
        this.bookedCount--
        this.seats[row][col] = 0
        return
    }

    cost := 1

    if col == 0 && this.seats[row][1] != 0 {
        cost = 3
    }

    if col == 3 && this.seats[row][2] != 0 {
        cost = 3
    }

    this.seats[row][col] = cost
    this.totalTime += cost
    this.bookedCount++
}

func (this *BusBooking) GetTotalTime() int {
    this.mu.Lock()
    defer this.mu.Unlock()

    return this.totalTime
}

func (this *BusBooking) GetMinTime() int {
    this.mu.Lock()
    defer this.mu.Unlock()

    return this.bookedCount
}
