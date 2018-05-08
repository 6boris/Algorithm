package main

import (
	"fmt"
	"math/rand"
	"time"
)

func SelectSort(array []int) {
	for i := 0; i < len(array); i++ {
		for j := i + 1; j < len(array); j++ {
			if array[i] > array[j] {
				array[i], array[j] = array[j], array[i]
			}
		}
	}

}

func main() {
	// 生成随机长度的的数组
	random := rand.New(rand.NewSource(time.Now().UnixNano()))
	array := make([]int, 10000)

	for i := range array {
		array[i] = random.Intn(100)
	}

	start := time.Now()
	SelectSort(array)
	rangeTime := time.Since(start)
	fmt.Println("Array Length: ", len(array))
	fmt.Println("Run Time:     ", rangeTime)
}
