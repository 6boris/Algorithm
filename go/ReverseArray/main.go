package main

import (
	"fmt"
	"math/rand"
	"time"
)

func ReverseArray(array []int) {
	i := 0
	u := len(array) - 1
	for i < u {
		array[i], array[u] = array[u], array[i]
		i, u = i+1, u-1
	}
}

func main() {
	// 生成随机长度的的数组
	random := rand.New(rand.NewSource(time.Now().UnixNano()))
	array := make([]int, 11)
	for i := range array {
		array[i] = random.Intn(100)
	}

	fmt.Println(array)

	start := time.Now()
	ReverseArray(array)
	rangeTime := time.Since(start)
	fmt.Println("Array Length: ", len(array))
	fmt.Println("Run Time:     ", rangeTime)
	fmt.Println(array)

}
