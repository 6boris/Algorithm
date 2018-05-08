package main

import (
	"fmt"
	"math/rand"
	"time"
)

func InsertSort(array []int) {
	for itemIndex, itemValue := range array {
		for itemIndex != 0 && array[itemIndex-1] > itemValue {
			array[itemIndex] = array[itemIndex-1]
			itemIndex--
		}
		array[itemIndex] = itemValue
	}
}

func InsertSortd(array []int) {
	var itemIndex, itemValue = 0, 0
	var j = 0
	for itemIndex = 0; itemIndex < len(array); itemIndex++ {
		itemValue = array[itemIndex]
		for j = itemIndex; j > 0; j-- {
			if array[j-1] > array[j] {
				array[j] = array[j-1]
			}
		}
		array[j] = itemValue
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
	InsertSort(array)
	rangeTime := time.Since(start)
	fmt.Println("Array Length: ", len(array))
	fmt.Println("Run Time:     ", rangeTime)
}
