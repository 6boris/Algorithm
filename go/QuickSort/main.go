package main

import (
	"fmt"
	"math/rand"
	"time"
)

func QuickSort(arr []int, start int, end int) {
	if start < end {
		i, j := start, end
		key := arr[start+end]
		for i < j {
			for arr[i] < key {
				i++
			}
			for arr[j] > key {
				j--
			}
			if i <= j {
				arr[i], arr[j] = arr[j], arr[i]
				i++
				j--
			}
			if start < j {
				QuickSort(arr, start, j)
			}
			if end > i {
				QuickSort(arr, i, end)
			}

		}
	}
}

func main() {
	// 生成随机长度的的数组
	random := rand.New(rand.NewSource(time.Now().UnixNano()))
	array := make([]int, 10)
	for i := range array {
		array[i] = random.Intn(100)
	}

	fmt.Println(array)
	arr := []int{1, 2, 5, 4, 3, 6, 8, 9, 0}
	start := time.Now()
	QuickSort(arr, 0, 9)
	rangeTime := time.Since(start)
	fmt.Println("Array Length: ", len(array))
	fmt.Println("Run Time:     ", rangeTime)
	fmt.Println(array)
}
